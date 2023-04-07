#ifndef GRAPHGENERATOR_H
#define GRAPHGENERATOR_H

#include "mathlist.h"
#include "graph.h"
#include "staticedge.h"
#include "undirectedge.h"
#include <unistd.h>

#include <algorithm>


struct ClusterGraph :
        public Graph
{
    ClusterGraph(int _number, int _numLinks) :
        Graph(_number), numLink_(_numLinks)
    {
        numClusters_ = 0;
    }
    ~ClusterGraph()
    {

    }
    void setCluster(Graph* _graph)
    {
        clusters_.push_back(_graph);
        numClusters_++;
    }
    void connected()
    {
        for(auto &iCluster1 : clusters_)
        {
            for(auto &iCluster2 : clusters_)
            {
                if (iCluster1->getNumber() < iCluster2->getNumber()) {
                    for (int i = 0; i < numLink_; i++)
                    {
                        vertex1_ = iCluster1->getVertex(static_cast<int>(ph::getRandomNumber(0, iCluster1->getVertexCount())));
                        vertex2_ = iCluster2->getVertex(static_cast<int>(ph::getRandomNumber(0, iCluster1->getVertexCount())));
                        setEdge(new DirectEdge(vertex1_, vertex2_, 1.0));
                        setEdge(new DirectEdge(vertex2_, vertex1_, 1.0));
                    }
                }
            }
        }
        for(auto &iCluster : clusters_)
        {
            setGraph(iCluster);
        }
    }
private:
    int numLink_;
    int numClusters_;
    Vertex* vertex1_;
    Vertex* vertex2_;
    std::vector<Graph*> clusters_;
//! functions:    
};


#endif // GRAPHGENERATOR_H
