#include "integratormodel.h"

IntegratorModel::IntegratorModel(DynamicNetwork* _network, Protocol* _protocol) :
    LinearModel(_network, _protocol)
{
    flagBasic_ = false;
    flagControl_ = true;
}

