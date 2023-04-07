#include "dynamicedge.h"

DynamicEdge::DynamicEdge(Oscillator* _first, Oscillator* _second, double _weight, double _lambda, double _tau) :
    Edge(_first, _second, _weight), lambda_(_lambda), tau_(_tau)
{
    setSelector();
}
DynamicEdge::~DynamicEdge()
{
    delete selector_;
}
double DynamicEdge::getWeight()
{
    double _time = 0;
    return (1 - selector_->select(_time)) * weight_;
}
double DynamicEdge::getLifeTime()
{
    return tau_;
}

void DynamicEdge::setSelector()
{
    selector_ = new IntervalSelector;
    std::default_random_engine generator_;
    std::exponential_distribution<double> distribution_(lambda_);
    double beginTime, endTime;
    double time = 0;
    while (time <= tau_)
    {
        beginTime = time + distribution_(generator_);
        endTime = beginTime + distribution_(generator_);
        selector_->setInterval(beginTime, endTime);
        time = time + endTime;
    }
}
