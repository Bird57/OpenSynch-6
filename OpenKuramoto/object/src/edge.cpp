#include "edge.h"


Edge::Edge(Oscillator* _first, Oscillator* _second, double _weight) :
    first_(_first), second_(_second), weight_(_weight)
{

}
Edge::~Edge()
{

}
void Edge::resetWeight(double _weight)
{
    weight_ = _weight;
}
Oscillator* Edge::getParentOscillator()
{
    return first_;
}
Oscillator* Edge::getChildOscillator()
{
    return second_;
}

