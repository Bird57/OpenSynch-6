#ifndef STATICEDGE_H
#define STATICEDGE_H

#include "edge.h"

struct StaticEdge
        : public Edge
{
    StaticEdge(Oscillator* _first, Oscillator* _second, double _weight);
    ~StaticEdge();
    double getWeight();
};

#endif // STATICEDGE_H
