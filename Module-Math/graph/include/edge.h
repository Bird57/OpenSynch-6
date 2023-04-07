#ifndef EDGE_H
#define EDGE_H

#include <map>
#include <random>
#include <iostream>

//#include <selector.h>

struct Vertex;

struct Edge
{
    Edge(Vertex* _first, Vertex* _second, double _weight);
    ~Edge();
    void resetWeight(double _weight);    
    std::string getType();
    Vertex* begin();
    Vertex* end();    
    virtual double getWeight() = 0;

//! new function:
    void setRealWeight(double _weight)
    {
        realweight_ = _weight;
    }
    double getRealWeight()
    {
        return realweight_;
    }
protected:
    double weight_;
    double realweight_;
    std::string type_;
    Vertex* first_;
    Vertex* second_;
};


#endif // EDGE_H
