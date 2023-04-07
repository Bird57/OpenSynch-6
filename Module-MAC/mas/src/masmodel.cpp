#include "masmodel.h"

MASModel::MASModel(DynamicNetwork* _network, Protocol* _protocol) :
   network_(_network), protocol_(_protocol)
{
    timecounter_ = getDynamicNetwork()->getTimeCounter();
}
MASModel::~MASModel()
{
    clear();
    list_.clear();
}

void MASModel::setDumpParameter(std::string _parameter)
{
    list_.push_back(_parameter);
}

void MASModel::setParameters()
{
    if (!list_.empty())
    {
        getDynamicNetwork()->getCollective()->update();
        std::cout << getDynamicNetwork()->getCollective()->getMeanState() << std::endl;

        for (auto &iParameter : list_)
        {
            if (iParameter == "desync")
            {
                desync_.push_back(std::make_pair(getDynamicNetwork()->getTimeCounter()->getTimeValue(), getDynamicNetwork()->getCollective()->getDesyncValue()));
            }
            else
            {
                for (auto &iAgent : *getDynamicNetwork()->getCollective()->getAgents())
                {
                    if (iParameter == "weight")
                    {
                        for (auto &iTriplet : iAgent->getTriplet())
                        {
                            weights_[getDynamicNetwork()->getTimeCounter()->getTimeValue()].push_back(
                            std::make_pair(std::make_pair(iAgent->getNumber(), iTriplet.first->getAgent()->getNumber()),
                                           iTriplet.first->getEdge()->getRealWeight()));
                        }
                    }
                    if (iParameter == "solve")
                    {
                        solve_[iAgent->getNumber()].push_back(std::make_pair(getDynamicNetwork()->getTimeCounter()->getTimeValue(),
                                                                             std::make_pair(iAgent->getAction(), iAgent->getControl())));
                    }
                    if (iParameter == "order")
                    {
                        int n = 0;
                        double sum = 0.0;
                        for (auto &iAgent : *getDynamicNetwork()->getCollective()->getAgents())
                        {
                            for (auto iNeighbor : *iAgent->getNeighbors())
                            {
                                sum += iNeighbor.second->getRealWeight();
                                n++;
                            }
                        }
                        order_.push_back(std::make_pair(getDynamicNetwork()->getTimeCounter()->getTimeValue(),
                                                         sum / n));
                    }
                }
            }
        }
    }
}

void MASModel::dump(std::string _address, std::string _name)
{
    std::string fullAddress;
    for (auto &iParameter : list_)
    {
        fullAddress = _address + _name + "_" + iParameter +".txt";
        std::ofstream out1(fullAddress, std::ios::out | std::ios::binary);
        if (iParameter == "solve")
        {
            for (auto &iAgent : solve_)
            {
                for (auto &iAction : iAgent.second)
                {

                    out1 << iAgent.first  << "   "
                         << iAction.first << "   " << iAction.second.first << "   " << iAction.second.second
                         << "\n";
                }
                out1 << std::endl;
            }

        }
        if (iParameter == "weight") {
            for (auto &iTimeSet : weights_)
            {
                for (auto &iEdge : iTimeSet.second)
                {
                    out1 << iTimeSet.first    << "   "
                         << iEdge.first.first << "   " << iEdge.first.second << "   " << iEdge.second
                         << "\n";
                }
                out1 << std::endl;
            }

        }
        if (iParameter == "desync") {
            for (auto &iTimeSet : desync_)
            {
                out1 << iTimeSet.first << "   " <<iTimeSet.second
                     << std::endl;
            }

        }
        if (iParameter == "order") {
            for (auto &iTimeSet : order_)
            {
                out1 << iTimeSet.first << "   " <<iTimeSet.second
                     << std::endl;
            }

        }
        out1.close();
    }
}
void MASModel::clear()
{
    desync_.clear();
    order_.clear();
    solve_.clear();
    weights_.clear();
}


DynamicNetwork* MASModel::getDynamicNetwork()
{
    return network_;
}
Protocol* MASModel::getProtocol()
{
    return protocol_;
}


/*
void MASModel::fdump()
{
    getDynamicNetwork()->getCollective()->update();
    for (auto &iAgent : *getDynamicNetwork()->getCollective()->getAgents())
    {
        //solve_[iAgent->getNumber()].push_back(std::make_pair(getDynamicNetwork()->getTimeCounter()->getTimeValue(), iAgent->getAction()));
        for (auto &iTriplet : iAgent->getTriplet())
        {
            weights_[getDynamicNetwork()->getTimeCounter()->getTimeValue()].push_back(
            std::make_pair(
                           std::make_pair(iAgent->getNumber(), iTriplet.first->getAgent()->getNumber()),
                           iTriplet.first->getEdge()->getRealWeight()));

        }

        solve_[iAgent->getNumber()].push_back(std::make_pair(getDynamicNetwork()->getTimeCounter()->getTimeValue(),
                                                             std::make_pair(iAgent->getAction(), iAgent->getControl())));

    }
    desync_.push_back(std::make_pair(getDynamicNetwork()->getTimeCounter()->getTimeValue(), getDynamicNetwork()->getCollective()->getDesyncValue()));

    int n = 0;
    double sum = 0.0;
    for (auto &iAgent : *getDynamicNetwork()->getCollective()->getAgents())
    {
        for (auto iNeighbor : *iAgent->getNeighbors())
        {
            sum += iNeighbor.second->getRealWeight();
            n++;
        }
    }
    order_.push_back(std::make_pair(getDynamicNetwork()->getTimeCounter()->getTimeValue(),
                                     sum / n));

}
*/



