#include "eulerscheme.h"

/*
double SymplexIntegration::getIntegral(std::function<double(ph::GreenKernel*, Vector3d, Vector3d)> _function, ph::GreenKernel* _green, Vector3d _r, BoundaryElement* _element)
{
    integral = 0.0;
    for (unsigned long i = 0; i < numNodes; i++)
    {
        integral += weightes[i] * _function(_green, _r, getTrianglePosition(i, _element));
    }
    return integral * _element->getArea();
}
*/

EulerScheme::EulerScheme()
{

}
EulerScheme::~EulerScheme()
{

}
void EulerScheme::solve(SynchronizationModel* _model, MaterialPointSystem* _system)
{
    timecounter_ = _system->getTimeCounter();    
    for (auto iObject : *_system->getMaterialPoints())
    {
        iObject->setInstantVelocity(_model->getSelfConsistentFunction(iObject));
        iObject->shiftValue(timecounter_->getTimeStep() * iObject->getInstantVelocity());
    }
}
