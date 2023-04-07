#ifndef STATICEDGE_H
#define STATICEDGE_H

#include "edge.h"
#include "vertex.h"

struct DirectEdge
        : public Edge
{
    DirectEdge(Vertex* _first, Vertex* _second, double _weight);
    ~DirectEdge();
    double getWeight();
};

#endif // STATICEDGE_H
