#include "wattsstrogatzgraph.h"

WattsStrogatzGraph::WattsStrogatzGraph(int _number, int _numVertex, int _numMeanNeighbors, double _beta) :
    Graph(_number), numVertex_(_numVertex), numMeanNeighbors_(_numMeanNeighbors), beta_(_beta)
{
    s.resize(numVertex_);
    t.resize(numMeanNeighbors_);

    switchEdge.resize(numMeanNeighbors_);
    //newVertices.resize(numVertex_);


    setGraph();
    setEdges();
}
WattsStrogatzGraph::~WattsStrogatzGraph()
{

}

double WattsStrogatzGraph::getRandom(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
bool WattsStrogatzGraph::compare(std::pair<int, double> x, std::pair<int, double> y)
{
    if (x.second == 0 && y.second == 0)
    {
        return y.first > x.first;
    }
    else
    {
        return x.second > y.second;
    }
}



void WattsStrogatzGraph::setGraph()
{
    double r;

    for (int i = 0; i < numVertex_; i++)
    {
        setVertex(new Vertex(i + 1));
        s[i] = (i + 1);
        for (int k = 0; k < numMeanNeighbors_; k++)
        {
            if (s[i] + k + 1 <= numVertex_) {
                t[k].push_back(s[i] + k + 1);
            } else
            {
                t[k].push_back(s[i] + k + 1 - numVertex_);
            }
        }
    }

    for (int i = 0; i < numVertex_; i++)
    {
        for (int j = 0; j < numVertex_; j++)
        {
            r = getRandom(0.0, 1.0);
            newVertices.push_back(std::pair(j + 1, r));
        }
        newVertices[i].second = 0;

        for (int k = 0; k < numMeanNeighbors_; k++)
        {

            r = getRandom(0.0, 1.0);
            switchEdge[k] = (r < beta_);

            newVertices[std::distance(t[k].begin(), find(t[k].begin(),t[k].end(), i + 1))].second = 0;
            if (!switchEdge[k]) {
                newVertices[t[k][i] - 1].second = 0;
            }

        }
        std::sort(newVertices.begin(), newVertices.end(), compare);

        int iter = 0;
        for (int k = 0; k < numMeanNeighbors_; k++)
        {
            if (switchEdge[k]) {
                t[k][i] = newVertices[iter].first;
                iter++;
            }
        }
    }
    newVertices.clear();

}
void WattsStrogatzGraph::setEdges()
{
    for (int j = 0; j < numVertex_; j++)
    {
        vertex1_ = getVertex(s[j]);
        for (int k = 0; k < numMeanNeighbors_; k++)
        {
            vertex2_ = getVertex(t[k][j]);
            setEdge(new DirectEdge(vertex1_, vertex2_, 1.0));
            setEdge(new DirectEdge(vertex2_, vertex1_, 1.0));
        }
    }
}
