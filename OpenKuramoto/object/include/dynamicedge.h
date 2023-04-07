#ifndef DYNAMICEDGE_H
#define DYNAMICEDGE_H

#include "edge.h"
#include "intervalselector.h"
#include "timecounter.h"

struct DynamicEdge :
        public Edge
{
    DynamicEdge(TimeCounter* _timecounter, Oscillator* _first, Oscillator* _second, double _weight, double _lambda);
    ~DynamicEdge();
    double getWeight();
private:
    double lambda_;
    std::string typeDistribution_;
    TimeCounter* timecounter_;
    IntervalSelector* selector_;
    void setSelector();
    double getLambda()
    {
        return lambda_;
    }
};

#endif // DYNAMICEDGE_H
