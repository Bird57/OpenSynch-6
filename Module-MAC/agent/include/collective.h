#ifndef COLLECTIVE_H
#define COLLECTIVE_H

#include "agent.h"
#include "timecounter.h"

struct Collective
{
    Collective();

    void clear();
    void update();
    void synchronize();

    int getDimension();
    int getAgentCount();

    void setAgent(Agent* _agent);
    std::vector<Agent*>* getAgents();

    void setSystemVector(Agent* _agent);
    void setSystemVector(VectorXd);
    VectorXd* getSystemVector();

//! new functions:
    double getMeanState()
    {
        double sum = 0.0;
        for (auto iAgent1 : agents_)
        {
            for (auto iAgent2 : agents_)
            {
                sum += iAgent1->getAction().norm();
            }
        }
        return sum / getAgentCount();
    }
    double getDesyncValue()
    {
        double sum = 0.0;
        for (auto iAgent1 : agents_)
        {
            for (auto iAgent2 : agents_)
            {
                sum += pow((iAgent1->getAction() - iAgent2->getAction()).norm(), 2);
            }
        }
        return sum / getAgentCount() / (getAgentCount() - 1);
    }
    VectorXd getMinState()
    {
        VectorXd vector;
        int s = 0;
        for (auto iAgent : agents_)
        {
            if (s == 0) {
                vector = iAgent->getAction();
            }
            else {
                if (iAgent->getAction().norm() < vector.norm()) {
                    vector = iAgent->getAction();
                }
            }
            s++;
        }
        return vector;
    }
    VectorXd getMaxState()
    {
        VectorXd vector;
        int s = 0;
        for (auto iAgent : agents_)
        {
            if (s == 0) {
                vector = iAgent->getAction();
            }
            else {
                if (iAgent->getAction().norm() > vector.norm()) {
                    vector = iAgent->getAction();
                }
            }
            s++;
        }
        return vector;
    }
private:
    int dim_;
    int numAgents_;
    VectorXd svector_;
    VectorXd cupvector_;
    TimeCounter* timecounter;
    std::vector<Agent*> agents_;
};

#endif // COLLECTIVE_H
