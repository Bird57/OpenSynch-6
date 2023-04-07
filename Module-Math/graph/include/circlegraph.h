#ifndef CIRCLEGRAPH_H
#define CIRCLEGRAPH_H

#include "graph.h"
#include "staticedge.h"


struct CircleGraph :
        public Graph
{
    CircleGraph(int _number, int _numVertex) :
        Graph(_number), numVertex_(_numVertex)
    {
        type_ = "undirected";
        setGraph();
    }
private:
    int numVertex_;
    Vertex* vertex1_;
    Vertex* vertex2_;

//! functions:
    void setGraph()
    {
            for (int i = 1; i <= numVertex_; i++)
            {
                setVertex(new Vertex(i));
            }
            for (int i = 1; i < numVertex_; i++)
            {
                vertex1_ = getVertex(i);
                vertex2_ = getVertex(i + 1);
                setEdge(new DirectEdge(vertex1_, vertex2_, 1.0));
                if (type_ == "undirected")
                {
                    setEdge(new DirectEdge(vertex2_, vertex1_, 1.0));
                }
            }
            vertex1_ = getVertex(numVertex_);
            vertex2_ = getVertex(1);
            setEdge(new DirectEdge(vertex1_, vertex2_, 1.0));
            if (type_ == "undirected")
            {
                setEdge(new DirectEdge(vertex2_, vertex1_, 1.0));
            }
        }
};


struct RegularGraph :
        public Graph
{
    RegularGraph(int _number, int _numVertex, int _step) :
        Graph(_number), numVertex_(_numVertex), step_(_step)
    {
        type_ = "directed";
        setGraph();
    }
private:
    int step_;
    int numVertex_;
    Vertex* vertex1_;
    Vertex* vertex2_;

//! functions:
    void setGraph()
    {
            for (int i = 1; i <= numVertex_; i++)
            {
                setVertex(new Vertex(i));
            }
            for (int i = 1; i < numVertex_; i++)
            {
                vertex1_ = getVertex(i);
                vertex2_ = getVertex(i + 1);
                setEdge(new DirectEdge(vertex1_, vertex2_, 1.0));
                if (type_ == "undirected")
                {
                    setEdge(new DirectEdge(vertex2_, vertex1_, 1.0));
                }
            }
            vertex1_ = getVertex(numVertex_);
            vertex2_ = getVertex(1);
            setEdge(new DirectEdge(vertex1_, vertex2_, 1.0));
            if (type_ == "undirected")
            {
                setEdge(new DirectEdge(vertex2_, vertex1_, 1.0));
            }

            for (int i = 1; i <= numVertex_; i++)
            {
                vertex1_ = getVertex(i);
                if (i + step_ <= numVertex_) {
                    vertex2_ = getVertex(i + step_);
                }
                else
                {
                    vertex2_ = getVertex(i + step_ - numVertex_);
                }
                setEdge(new DirectEdge(vertex1_, vertex2_, 1.0));
                if (type_ == "undirected")
                {
                    setEdge(new DirectEdge(vertex2_, vertex1_, 1.0));
                }
            }

        }
};


#endif // CIRCLEGRAPH_H
