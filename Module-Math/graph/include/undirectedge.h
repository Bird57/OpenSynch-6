#ifndef UNDIRECTEDGE_H
#define UNDIRECTEDGE_H

#include "edge.h"
#include "vertex.h"

struct UndirectEdge
        : public Edge
{
    UndirectEdge(Vertex* _first, Vertex* _second, double _weight);
    ~UndirectEdge();
    double getWeight();
};

#endif // UNDIRECTEDGE_H
