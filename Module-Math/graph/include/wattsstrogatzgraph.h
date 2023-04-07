#ifndef WATTSSTROGATZGRAPH_H
#define WATTSSTROGATZGRAPH_H

#include "graph.h"
#include "staticedge.h"
#include "undirectedge.h"
#include <unistd.h>

#include <algorithm>

struct WattsStrogatzGraph :
        public Graph
{
    WattsStrogatzGraph(int _number, int _numVertex, int _numMeanNeighbors, double _beta);
    ~WattsStrogatzGraph();
private:
    int numVertex_;
    int numMeanNeighbors_;
    double beta_;
    Vertex* vertex1_;
    Vertex* vertex2_;

    std::vector<int> s;
    std::vector<std::vector<int>> t;

    std::vector<int> switchEdge;
    std::vector<std::pair<int, double>> newVertices;

//! functions:
    double getRandom(double fMin, double fMax);
    static bool compare(std::pair<int, double> x, std::pair<int, double> y);
    void setGraph();
    void setEdges();
};


#endif // WATTSSTROGATZGRAPH_H
