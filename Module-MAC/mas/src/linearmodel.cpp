#include "linearmodel.h"

LinearModel::LinearModel(DynamicNetwork* _network, Protocol* _protocol) :
    MASModel(_network, _protocol)
{
    flagBasic_ = true;
    flagControl_ = true;
}

VectorXd LinearModel::getEquationFunction(VectorXd& _svector)
{
    //! (1) Set new S-Vector:
    getDynamicNetwork()->getCollective()->setSystemVector(_svector);
    //! (2) Set control vector:
    vector = VectorXd(getDynamicNetwork()->getCollective()->getDimension());
    int i = 0;
    for (auto &iAgent : *getDynamicNetwork()->getCollective()->getAgents())
    {
        iAgent->setControl(getProtocol()->getControlFunction(iAgent));
        //cupvector_ = getProtocol()->getControlFunction(iAgent);
        cupvector_ = iAgent->getControl();
        for (int s = 0; s < cupvector_.size(); s++)
        {
            vector(i) = cupvector_(s);
            i++;
        }
    }
    return vector;
}

void LinearModel::setEquation(std::pair<MatrixXd, MatrixXd> _pair)
{
    basicmatrix_ = MatrixXd::Zero(getDynamicNetwork()->getCollective()->getDimension(),
                        getDynamicNetwork()->getCollective()->getDimension());
    controlmatrix_ = MatrixXd::Zero(getDynamicNetwork()->getCollective()->getDimension(),
                          getDynamicNetwork()->getCollective()->getDimension());
    int s = 0;
    for (auto &iAgent : *getDynamicNetwork()->getCollective()->getAgents())
    {
        basicmatrix_.block(s,s,iAgent->getDimension(),iAgent->getDimension()) = _pair.first;
        controlmatrix_.block(s,s,iAgent->getDimension(),iAgent->getDimension()) = _pair.second;
        s = s + iAgent->getDimension();
    }
    //basicmatrix_ = _pair.first;
    //controlmatrix_ = _pair.second;
}

