#include "nonadditiveprotocol.h"

NonadditiveProtocol::NonadditiveProtocol(Connection* _connection) :
    Protocol(), connection_(_connection)
{

}
VectorXd NonadditiveProtocol::getControlFunction(Agent* _agent)
{    
    double x_i, x_j, x_k;
    double control, sum;
    double numTriplets;

    x_i = _agent->getAction()(0);

    control = 0.0;
    for (auto iNeighbors : *_agent->getNeighbors())
    {
        sum = 0.0;
        numTriplets = 0.0;
        for (auto iTriplet : _agent->getTriplet())
        {
            if ((iTriplet.first->getAgent() == iNeighbors.first) or (iTriplet.second->getAgent() == iNeighbors.first)) {
                x_j = iTriplet.first->getAgent()->getAction()(0);
                x_k = iTriplet.second->getAgent()->getAction()(0);
                sum += 0.5 * (iTriplet.first->getEdge()->getWeight() + iTriplet.second->getEdge()->getWeight())
                         * connection_->getFunction(x_i, x_j, x_k);

                numTriplets++;
            }
            //std::cout << numTriplets << std::endl;
        }
        iNeighbors.second->setRealWeight(sum/numTriplets);

        x_j = iNeighbors.first->getAction()(0);
        control += iNeighbors.second->getRealWeight() *
               (x_j - x_i);

    }
/*
    std::cout << "x" << _agent->getNumber() << " = " << _agent->getAction()(0) << ";  "
                 "u" << _agent->getNumber() << " = " << control << std::endl;
*/
    VectorXd vec(1);
    vec << control;
    return vec;
}
