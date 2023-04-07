#include "targetprotocol.h"

TargetProtocol::TargetProtocol() :
    Protocol()
{

}
VectorXd TargetProtocol::getControlFunction(Agent* _agent)
{
    double x_i, x_j, psi;
    double control, sum;

    std::vector<double> vector;

    x_i = _agent->getAction()(0);
    for (auto iTarget : _agent->getTargets())
    {
        psi = iTarget->getPosition()(0);
        sum = 0.0;
        for (auto iNeighbor : *_agent->getNeighbors())
        {
            x_j = iNeighbor.first->getAction()(0);
            sum += iNeighbor.second->getWeight() *
                    connection_->getFunction(x_i, psi, x_j);
        }
        vector.push_back(sum);
    }
    auto iWeight = std::max_element(vector.begin(), vector.end());

    psi = _agent->getTarget(std::distance(vector.begin(), iWeight))->getPosition()(0);
    control = *iWeight * (psi - x_i);
/*
    std::cout << "x" << _agent->getNumber() << " = " << _agent->getAction()(0) << ";  "
                 "u" << _agent->getNumber() << " = " << control << std::endl;
*/
    VectorXd vec(1);
    vec << control;

    return vec;
}
