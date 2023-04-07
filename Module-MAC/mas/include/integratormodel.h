#ifndef INTEGRATORMODEL_H
#define INTEGRATORMODEL_H

#include "linearmodel.h"

struct IntegratorModel
        : public  LinearModel
{
    IntegratorModel(DynamicNetwork* _network, Protocol* _protocol);

private:
    VectorXd cupvector_;
    VectorXd vector;
};


#endif // INTEGRATORMODEL_H
