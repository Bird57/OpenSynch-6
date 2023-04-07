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
    Oscillator* getFirstOscillator();
    Oscillator* getSecondOscillator();
    virtual double getWeight() = 0;
protected:
    double weight_;
    std::string type_;
    Oscillator* first_;
    Oscillator* second_;
};


struct StaticEdge
        : public Edge
{
    StaticEdge(Oscillator* _first, Oscillator* _second, double _weight);
    ~StaticEdge();
    double getWeight();
};

#endif // EDGE_H
