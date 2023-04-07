#ifndef PROTOCOL_H
#define PROTOCOL_H

#include "agent.h"

struct Protocol
{
    Protocol()
    {

    }
    virtual VectorXd getControlFunction(Agent* _agent) = 0;
};


#endif // PROTOCOL_H
