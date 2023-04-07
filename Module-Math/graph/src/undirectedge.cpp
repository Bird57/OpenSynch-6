#include "undirectedge.h"

UndirectEdge::UndirectEdge(Vertex* _first, Vertex* _second, double _weight) :
    Edge(_first,_second, _weight)
{
    type_ = "undirect";
    _first->setEdge(this);
    _second->setEdge(this);
}
UndirectEdge::~UndirectEdge()
{

}
double UndirectEdge::getWeight()
{
    return weight_;
}

