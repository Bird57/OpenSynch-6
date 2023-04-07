#include "edge.h"


Edge::Edge(Vertex* _first, Vertex* _second, double _weight) :
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
std::string Edge::getType()
{
    return type_;
}
Vertex* Edge::begin()
{
    return first_;
}
Vertex* Edge::end()
{
    return second_;
}



