#ifndef DYNAMICNETWORK_H
#define DYNAMICNETWORK_H

#include <mathlist.h>
#include "graph.h"
#include "agent.h"
#include "collective.h"

struct DynamicNetwork
{
    DynamicNetwork(TimeCounter* _timecounter, Graph* _graph, Collective* _collective);
    ~DynamicNetwork();

    Collective* getCollective();
    TimeCounter* getTimeCounter()
    {
        return timecounter_;
    }
private:
    TimeCounter* timecounter_;
    Graph* graph_;
    Collective* collective_;
    void distribute();

};

#endif // DYNAMICNETWORK_H
