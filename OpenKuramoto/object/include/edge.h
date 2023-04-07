#ifndef EDGE_H
#define EDGE_H

#include <map>
#include <random>
#include <iostream>
#include <selector.h>

struct Oscillator;

struct Edge
{
    Edge(Oscillator* _first, Oscillator* _second, double _weight);
    ~Edge();
    void resetWeight(double _weight);
    Oscillator* getParentOscillator();
    Oscillator* getChildOscillator();
    virtual double getWeight() = 0;
protected:
    double weight_;
    std::string type_;
    Oscillator* first_;
    Oscillator* second_;
};


#endif // EDGE_H
