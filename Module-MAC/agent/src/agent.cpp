#include "agent.h"

Agent::Agent(int _number, VectorXd _state) :
    number_(_number), state_(_state)
{
    numNeighbors = 0;
    numTriplets = 0;
    dim_ = state_.size();
}
Agent::Agent(int _number, VectorXd _state, std::vector<Target*> _targets) :
    number_(_number), state_(_state), targets_(_targets)
{
    numNeighbors = 0;
    numTriplets = 0;
    dim_ = state_.size();
}
Agent::~Agent()
{

}


void Agent::setVertex(Vertex* _vertex)
{
    _vertex->setAgent(this);
    vertex_ = _vertex;
}
void Agent::setNeighbors()
{    
    for (auto &iNeighbor : vertex_->getNeighbors())
    {
        neighbors_.push_back(std::make_pair(iNeighbor.first->getAgent(), iNeighbor.second));
        numNeighbors++;
    } 
}
void Agent::setTriplet()
{
    for (auto &iNeighbor1 : vertex_->getNeighbors())
    {
        for (auto &iNeighbor2 : vertex_->getNeighbors())
        {
            if (iNeighbor1.first != iNeighbor2.first) {
                triplet_.push_back(std::make_pair(new Neighbor(iNeighbor1.first->getAgent(), iNeighbor1.second),
                                                  new Neighbor(iNeighbor2.first->getAgent(), iNeighbor2.second)));
            }
            numTriplets++;
        }
    }
}
Vertex* Agent::getVertex()
{
    return vertex_;
}

int Agent::getDimension()
{
    return dim_;
}

int Agent::getNumber()
{
    return number_;
}

std::vector<std::pair<Agent*, Edge*>>* Agent::getNeighbors()
{
    return &neighbors_;
}
std::vector<std::pair<Agent*, Edge*>> Agent::getNeighborsCopy()
{
    return neighbors_;
}

std::vector<std::pair<Neighbor*, Neighbor*>> Agent::getTriplet()
{
    return triplet_;
}


