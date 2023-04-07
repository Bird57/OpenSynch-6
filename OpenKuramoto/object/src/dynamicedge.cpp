#include "dynamicedge.h"

DynamicEdge::DynamicEdge(TimeCounter* _timecounter, Oscillator* _first, Oscillator* _second, double _weight, double _lambda) :
    timecounter_(_timecounter), Edge(_first, _second, _weight), lambda_(_lambda)
{
    setSelector();
}
DynamicEdge::~DynamicEdge()
{
    delete selector_;
}
double DynamicEdge::getWeight()
{
    return (1 - selector_->select(timecounter_->getTimeValue())) * weight_;
}

void DynamicEdge::setSelector()
{
    selector_ = new IntervalSelector;
    std::default_random_engine generator;
    std::exponential_distribution<double> distribution(getLambda());
    double beginTime, endTime;
    double time = 0;
    while (time <= timecounter_->end())
    {
        beginTime = time + distribution(generator);
        endTime = beginTime + distribution(generator);
        selector_->setInterval(beginTime, endTime);
        time = time + endTime;
    }
}
