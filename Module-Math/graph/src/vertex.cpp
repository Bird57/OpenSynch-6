#include "vertex.h"

Vertex::Vertex(int _number) :
    number_(_number)
{

}

int Vertex::getNumber()
{
    return number_;
}

void Vertex::setEdge(Edge* edge_)
{
    edges_.push_back(edge_);
}
std::vector<Edge*>* Vertex::getEdges()
{
    return &edges_;
}
std::vector<std::pair<Vertex*, Edge*>> Vertex::getNeighbors()
{
    std::vector<std::pair<Vertex*, Edge*>> collect;
    for (auto &iEdge : *getEdges())
    {
        if (iEdge->getType() == "direct") {
            collect.push_back(std::make_pair(iEdge->begin(), iEdge));
        }
        if (iEdge->getType() == "undirect") {
            if (iEdge->begin() == this) {
                collect.push_back(std::make_pair(iEdge->end(), iEdge));
            }
            else {
                collect.push_back(std::make_pair(iEdge->begin(), iEdge));
            }
        }
    }
    return collect;
}

void Vertex::setAgent(Agent* _agent)
{
    agent_ = _agent;
}
Agent* Vertex::getAgent()
{
    return agent_;
}
