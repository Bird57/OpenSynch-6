#include "staticedge.h"

DirectEdge::DirectEdge(Vertex* _first, Vertex* _second, double _weight) :
    Edge(_first,_second, _weight)
{
    type_ = "direct";
    //_first->setEdge(this);
    _second->setEdge(this);
}
DirectEdge::~DirectEdge()
{

}
double DirectEdge::getWeight()
{
    return weight_;
}



