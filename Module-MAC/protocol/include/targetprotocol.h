#ifndef TARGETPROTOCOL_H
#define TARGETPROTOCOL_H

#include "protocol.h"
#include "connection.h"

struct TargetProtocol
        : public Protocol
{
    TargetProtocol();
    double getHfunction(double _x1, double x_2)
    {
        return _x1 - x_2;
    }    
    VectorXd getControlFunction(Agent* _agent);
private:
    double tau;
    Connection* connection_;
};


#endif // TARGETPROTOCOL_H
