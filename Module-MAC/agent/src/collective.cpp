#include "collective.h"


Collective::Collective()
{
    dim_ = 0;
    numAgents_ = 0;
    svector_.resize(0);
}

void Collective::clear()
{
    numAgents_ = 0;
    agents_.clear();
}
void Collective::update()
{
    int s = 0;
    for (auto &iAgent : agents_)
    {
        cupvector_ = iAgent->getPercept();
        for (int i = 0; i < iAgent->getDimension(); i++)
        {
            cupvector_(i) = svector_(s + i);
        }
        iAgent->setPercept(cupvector_);
        s = s + iAgent->getDimension();
    }
}
void Collective::synchronize()
{
    for (auto &iAgent : agents_)
    {
        iAgent->setNeighbors();
        iAgent->setTriplet();
    }    
}

int Collective::getDimension()
{
    return dim_;
}
int Collective::getAgentCount()
{
    return numAgents_;
}
void Collective::setAgent(Agent* _agent)
{
    agents_.push_back(_agent);
    setSystemVector(_agent);
    numAgents_++;
}
std::vector<Agent*>* Collective::getAgents()
{
    return &agents_;
}

VectorXd* Collective::getSystemVector()
{
    return &svector_;
}

//! private:
//!
void Collective::setSystemVector(VectorXd _svector)
{
    svector_ = _svector;
    dim_ = svector_.size();
    update();
}

void Collective::setSystemVector(Agent* _agent)
{
    cupvector_ = svector_;
    svector_.resize(getDimension() + _agent->getAction().size());
    svector_ << cupvector_, _agent->getAction();
    dim_ = getDimension() + _agent->getAction().size();
}




