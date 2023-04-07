#include "simpleprotocol.h"
#include <cstdlib>

SimplePairProtocol::SimplePairProtocol() :
    Protocol()
{

}
VectorXd SimplePairProtocol::getControlFunction(Agent* _agent)
{
    VectorXd sum = 0.0 * _agent->getAction();
    for (auto &iNeighbor : *_agent->getNeighbors())
    {
        sum += iNeighbor.second->getWeight() * (iNeighbor.first->getAction() - _agent->getAction());
    }
    return sum;
}




GeometricMeanPairProtocol::GeometricMeanPairProtocol() :
    Protocol()
{

}
VectorXd GeometricMeanPairProtocol::getControlFunction(Agent* _agent)
{
    VectorXd sum = 0.0 * _agent->getAction();
    for (auto &iNeighbor : *_agent->getNeighbors())
    {
        sum += iNeighbor.second->getWeight() * (iNeighbor.first->getAction() - _agent->getAction());
    }
    return _agent->getAction() * sum;
}
