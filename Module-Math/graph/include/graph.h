#ifndef GRAPH_H
#define GRAPH_H

#include "vertex.h"
#include "edge.h"
#include <fstream>

struct Graph
{
    Graph(int _number);
    ~Graph();
    void setEdge(Edge* _edge);
    void setVertex(Vertex* _vertex);
    void setGraph(Graph* graph);

    int getNumber()
    {
        return number_;
    }
    int getVertexCount()
    {
        return numVertices;
    }
    Vertex* getVertex(int _number);
    std::vector<Vertex*>* getVertices();
    std::vector<Edge*>* getEdges();

//! New functions:
    void dump(std::string _address, std::string _name);
protected:
    int number_;
    int numEdges;
    int numVertices;
    std::string type_;
    std::vector<Edge*> edges_;
    std::vector<Vertex*> vertices_;
};

#endif // GRAPH_H
