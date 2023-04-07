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
Oscillator* Edge::getFirstOscillator()
{
    return first_;
}
Oscillator* Edge::getSecondOscillator()
{
    return second_;
}


StaticEdge::StaticEdge(Oscillator* _first, Oscillator* _second, double _weight) :
    Edge(_first, _second, _weight)
{

}
StaticEdge::~StaticEdge()
{

}
double StaticEdge::getWeight()
{
    return weight_;
}


