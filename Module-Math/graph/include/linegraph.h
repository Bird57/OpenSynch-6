#ifndef LINEGRAPH_H
#define LINEGRAPH_H

#include "graph.h"
#include "staticedge.h"


struct LineGraph :
        public Graph
{
    LineGraph(int _number, int _numVertex, int _numVertex1, int _numVertex2) :
        Graph(_number), numVertex_(_numVertex), numVertex1_(_numVertex1), numVertex2_(_numVertex2)
    {
        setGraph();
    }
private:
    int numVertex_;
    int numVertex1_;
    int numVertex2_;
    Vertex* vertex1_;
    Vertex* vertex2_;

//! functions:
    void setGraph()
    {
        for (int i = 1; i <= numVertex_; i++)
        {
            setVertex(new Vertex(i));
        }
        vertex1_ = getVertex(1);
        vertex2_ = getVertex(numVertex1_);
        setEdge(new DirectEdge(vertex1_, vertex2_, 1.0));
        setEdge(new DirectEdge(vertex2_, vertex1_, 1.0));
        for (int i = 1; i < numVertex_; i++)
        {
            vertex1_ = getVertex(i);
            vertex2_ = getVertex(i + 1);
            setEdge(new DirectEdge(vertex1_, vertex2_, 1.0));
            setEdge(new DirectEdge(vertex2_, vertex1_, 1.0));
        }
        vertex1_ = getVertex(numVertex_);
        vertex2_ = getVertex(numVertex_ - numVertex2_ + 1);
        setEdge(new DirectEdge(vertex1_, vertex2_, 1.0));
        setEdge(new DirectEdge(vertex2_, vertex1_, 1.0));
    }
};

#endif // LINEGRAPH_H
