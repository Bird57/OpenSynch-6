#ifndef NONADDITIVEPROTOCOL_H
#define NONADDITIVEPROTOCOL_H

#include "protocol.h"
#include "connection.h"


struct NonadditiveProtocol
        : public Protocol
{
    NonadditiveProtocol(Connection* connection_);
    VectorXd getControlFunction(Agent* _agent);
private:
    Connection* connection_;
};

#endif // NONADDITIVEPROTOCOL_H
