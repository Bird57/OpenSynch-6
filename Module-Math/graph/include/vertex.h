#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include "edge.h"

struct Agent;

struct Vertex
{
    Vertex(int _number);

    int getNumber();

    void setNewNumber(int _number)
    {
        number_ = _number;
    }
    void setEdge(Edge* edge_);
    std::vector<Edge*>* getEdges();

    std::vector<std::pair<Vertex*, Edge*>> getNeighbors();

//! Дополнительные функции для фиксации агента:
    void setAgent(Agent* _agent);
    Agent* getAgent();
private:
    int number_;    
    std::vector<Edge*> edges_;
//! Дополнительные переменные для фиксации агента:
    Agent* agent_;
};


#endif // VERTEX_H
