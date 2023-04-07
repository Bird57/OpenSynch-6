#ifndef SIMPLEPROTOCOL_H
#define SIMPLEPROTOCOL_H

#include "protocol.h"

struct SimplePairProtocol
        : public Protocol
{
    SimplePairProtocol();
    VectorXd getControlFunction(Agent* _agent);
};

struct GeometricMeanPairProtocol
        : public Protocol
{
    GeometricMeanPairProtocol();
    VectorXd getControlFunction(Agent* _agent);
};

#endif // SIMPLEPROTOCOL_H
