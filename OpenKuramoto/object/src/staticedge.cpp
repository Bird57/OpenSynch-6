#include "staticedge.h"

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


