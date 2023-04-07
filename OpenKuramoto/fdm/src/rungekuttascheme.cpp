#include "rungekuttascheme.h"

RungeKuttaScheme::RungeKuttaScheme()
{

}
RungeKuttaScheme::~RungeKuttaScheme()
{

}
void RungeKuttaScheme::solve(SynchronizationModel* _model, MaterialPointSystem* _system)
{
/*
    system_1->copy(system_);
    system_2->copy(system_);
    system_3->copy(system_);

    for (auto iOscillator : *system_->getOscilators())
    {
        oscillator_1 = system_1->getOscilator(iOscillator->getNumber());
        oscillator_2 = system_2->getOscilator(iOscillator->getNumber());
        oscillator_1->setInstantFrequency(getSelfConsistentFrequency(oscillator_1));
        oscillator_2->shiftAngle(0.5 * timecouter_->getTimeStep() * oscillator_1->getInstantFrequency());
        iOscillator->shiftAngle((1.0 / 6.0) * timecouter_->getTimeStep() * oscillator_1->getInstantFrequency());
    }
    for (auto iOscillator : *system_->getOscilators())
    {
        oscillator_1 = system_1->getOscilator(iOscillator->getNumber());
        oscillator_2 = system_2->getOscilator(iOscillator->getNumber());
        oscillator_2->setInstantFrequency(getSelfConsistentFrequency(oscillator_2));
        oscillator_1->shiftAngle(0.5 * timecouter_->getTimeStep() * oscillator_2->getInstantFrequency());
        iOscillator->shiftAngle((1.0 / 3.0) * timecouter_->getTimeStep() * oscillator_2->getInstantFrequency());
    }
    for (auto iOscillator : *system_->getOscilators())
    {
        oscillator_1 = system_1->getOscilator(iOscillator->getNumber());
        oscillator_2 = system_3->getOscilator(iOscillator->getNumber());
        oscillator_1->setInstantFrequency(getSelfConsistentFrequency(oscillator_1));
        oscillator_2->shiftAngle(timecouter_->getTimeStep() * oscillator_1->getInstantFrequency());
        iOscillator->shiftAngle((1.0 / 3.0) * timecouter_->getTimeStep() * oscillator_1->getInstantFrequency());
    }
    for (auto iOscillator : *system_->getOscilators())
    {
        oscillator_2 = system_3->getOscilator(iOscillator->getNumber());
        oscillator_2->setInstantFrequency(getSelfConsistentFrequency(oscillator_2));
        iOscillator->shiftAngle((1.0 / 6.0) * timecouter_->getTimeStep() * oscillator_2->getInstantFrequency());
    }

*/

}
