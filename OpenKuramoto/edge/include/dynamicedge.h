#ifndef DYNAMICEDGE_H
#define DYNAMICEDGE_H

#include "edge.h"
#include "intervalselector.h"

struct DynamicEdge :
        public Edge
{
    DynamicEdge(Oscillator* _first, Oscillator* _second, double _weight, double _lambda, double _tau);
    ~DynamicEdge();
    double getWeight();
    double getLifeTime();
private:
    double lambda_;
    double tau_;
    std::string typeDistribution_;
    IntervalSelector* selector_;
    void setSelector();
};

#endif // DYNAMICEDGE_H
