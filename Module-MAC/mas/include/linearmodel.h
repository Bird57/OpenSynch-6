#ifndef LINEARMODEL_H
#define LINEARMODEL_H

#include "masmodel.h"

struct LinearModel
        : public  MASModel
{
    LinearModel(DynamicNetwork* _network, Protocol* _protocol);

    void setEquation(std::pair<MatrixXd, MatrixXd> _pair);

    VectorXd getEquationFunction(VectorXd& _svector);

private:
    VectorXd cupvector_;
    VectorXd vector;    
};

#endif // LINEARMODEL_H
