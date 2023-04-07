#include "dynamicnetwork.h"


DynamicNetwork::DynamicNetwork(TimeCounter* _timecounter, Graph* _graph, Collective* _collective) :
    timecounter_(_timecounter), graph_(_graph), collective_(_collective)
{
    distribute();
}
DynamicNetwork::~DynamicNetwork()
{

}

Collective* DynamicNetwork::getCollective()
{
    return collective_;
}

//protected:
void DynamicNetwork::distribute()
{
    for(auto iAgent : *collective_->getAgents())
    {
        iAgent->setVertex(graph_->getVertex(iAgent->getNumber()));
    }
    collective_->synchronize();
}
