#ifndef AGENT_H
#define AGENT_H

#include <mathlist.h>
#include "vertex.h"
#include "edge.h"

struct Target
{
    Target(int _number, VectorXd _position) :
        number_(_number), position_(_position)
    {

    }
    VectorXd getPosition()
    {
        return position_;
    }
private:
    int number_;
    VectorXd position_;
};


struct Neighbor
{
    Neighbor(Agent* _agent, Edge* _edge) :
        agent_(_agent), edge_(_edge)
    {

    }
    ~Neighbor()
    {

    }
    Agent* getAgent()
    {
        return agent_;
    }
    Edge* getEdge()
    {
        return edge_;
    }
private:
    int number_;
    Agent* agent_;
    Edge* edge_;
};



struct Agent        
{
    Agent(int _number, VectorXd _state);
    Agent(int _number, VectorXd _state, std::vector<Target*> _targets);

    ~Agent();

    virtual void setPercept(VectorXd _percept) = 0;
    virtual void setControl(VectorXd _control) = 0;
    virtual VectorXd getPercept() = 0;
    virtual VectorXd getAction() = 0;
    virtual VectorXd getControl() = 0;

    void setVertex(Vertex* _vertex);
    void setNeighbors();
    void setTriplet();

    int getDimension();

    Vertex* getVertex();

    int getNumber();

    std::vector<std::pair<Agent*, Edge*>>* getNeighbors();
    std::vector<std::pair<Agent*, Edge*>> getNeighborsCopy();

    std::vector<std::pair<Neighbor*, Neighbor*>> getTriplet();


    std::vector<Target*> getTargets()
    {
        return targets_;
    }
    Target* getTarget(int number)
    {
        return targets_[number];
    }
protected:
    int dim_;
    int number_;
    int numNeighbors;
    int numTriplets;
    VectorXd state_;
    VectorXd control_;
    Vertex* vertex_;
    std::vector<std::pair<Agent*, Edge*>> neighbors_;
    std::vector<std::pair<Neighbor*, Neighbor*>> triplet_;
    std::vector<Target*> targets_;
};




#endif // AGENT_H
