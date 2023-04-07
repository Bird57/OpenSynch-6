#include "graph.h"

Graph::Graph(int _number) :
    number_(_number)
{
    numEdges = 0;
    numVertices = 0;
}
Graph::~Graph()
{

}
void Graph::setEdge(Edge* _edge)
{
    edges_.push_back(_edge);
    numEdges++;
}

void Graph::setVertex(Vertex* _vertex)
{
    vertices_.push_back(_vertex);
    numVertices++;
}
void Graph::setGraph(Graph* _graph)
{
    for (auto iVertex : *_graph->getVertices())
    {
        numVertices++;
        iVertex->setNewNumber(numVertices);
        vertices_.push_back(iVertex);
    }
    for (auto iEdge : *_graph->getEdges())
    {
        edges_.push_back(iEdge);
        numEdges++;
    }
}
Vertex* Graph::getVertex(int _number)
{
    for(auto iVertex : vertices_)
    {
        if (iVertex->getNumber() == _number)
        {
            return iVertex;
        }
    }
    return vertices_.back();
}
std::vector<Vertex*>* Graph::getVertices()
{
    return &vertices_;
}
std::vector<Edge*>* Graph::getEdges()
{
    return &edges_;
}
//! New functions:
void Graph::dump(std::string _address, std::string _name)
{
    std::string fullAddress;
    fullAddress = _address + _name + ".txt";
    std::ofstream out(fullAddress, std::ios::out | std::ios::binary);

    int s, t;
    for (auto iVertex : vertices_)
    {
        s = iVertex->getNumber();
        for (auto iNeighbors  : iVertex->getNeighbors())
        {
            t = iNeighbors.first->getNumber();
            //if (s < t) {
                out << s << "  " << t << "  " << "\n";
            //}
        }
    }
    out.close();

}
