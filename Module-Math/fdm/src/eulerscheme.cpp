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

EulerScheme::EulerScheme(Model* _model) :
    FiniteDifferenceMethod(_model)
{

}
EulerScheme::EulerScheme(Model* _model, std::string _address, std::string _name) :
    FiniteDifferenceMethod(_model, _address, _name)
{

}
EulerScheme::~EulerScheme()
{

}
void EulerScheme::solve(VectorXd* _X)
{
    while(!timecounter_->isFinished())
    {
        timecounter_->shift();
        std::cout << "Iteration number of: " << timecounter_->getCount() << std::endl;
        *_X += timecounter_->getTimeStep() * (getModel()->getControlMatrix() * getModel()->getEquationFunction(*_X));
        getModel()->setParameters();
    }    
    std::cout << "Model is compute!"    << std::endl
              << "Exit..."              << std::endl;
    timecounter_->reset();
}
