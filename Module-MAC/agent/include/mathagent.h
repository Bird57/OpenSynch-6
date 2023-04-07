#ifndef MATHAGENT_H
#define MATHAGENT_H

#include "agent.h"

struct MathAgent
        : public Agent
{
    MathAgent(int _number, VectorXd _state);
    MathAgent(int _number, VectorXd _state, std::vector<Target*> targets_);
    ~MathAgent();
    void setPercept(VectorXd _percept);
    void setControl(VectorXd _percept);

    VectorXd getPercept();
    VectorXd getAction();
    VectorXd getControl();
    void setVertex(Vertex* _vertex);
    Vertex* getVertex();

    int getNumber();
};

#endif // MATHAGENT_H
