#include "kuromotomodel.h"


KuromotoModel::KuromotoModel(OscillatorSystem* _system, FiniteDifferenceMethod* _scheme) :
    SynchronizationModel(_system), scheme_(_scheme)
{

}
KuromotoModel::~KuromotoModel()
{

}

void KuromotoModel::compute()
{
    system_->getTimeCounter()->reset();
    while(!system_->getTimeCounter()->isFinished())
    {
        system_->getTimeCounter()->shift();
        std::cout << "Iteration number of: " << system_->getTimeCounter()->getCount() << std::endl;
        scheme_->solve(this, system_);
        if (flag_) {
            system_->dump(address_, name_ +  "_" + std::to_string(system_->getTimeCounter()->getCount()));
        }
    }
    std::cout << "Model is compute!" << std::endl
         << "Exit..." << std::endl;
}
double KuromotoModel::getSelfConsistentFunction(MaterialPoint* _object)
{
    oscillator_ = system_->getOscilator(_object->getNumber());
    delta_ = oscillator_->getSelfFrequency();
    for (auto iOscillator : *system_->getOscilators())
    {
        delta_ += (oscillator_->getConnection(iOscillator)->getWeight() / system_->getCount()) * sin(iOscillator->getValue() - oscillator_->getValue());
    }
    return delta_;
}
