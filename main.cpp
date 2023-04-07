#include <random>
#include <memory>


#include "mathagent.h"
#include "collective.h"
#include "graph.h"
#include "undirectedge.h"
#include "staticedge.h"
#include "dynamicnetwork.h"
#include "simpleprotocol.h"
#include "nonadditiveprotocol.h"
#include "targetprotocol.h"
#include "linearmodel.h"

#include "eulerscheme.h"
#include "wattsstrogatzgraph.h"
#include "graphgenerator.h"
#include "circlegraph.h"
#include "linegraph.h"

class Manager
{

    void setTargets()
    {
        VectorXd vec(1);
        std::vector<Target*> targets;
        vec << 11.0;
        targets.push_back(new Target(1, vec));
        vec << 23.0;
        targets.push_back(new Target(2, vec));
        vec << 29.0;
        targets.push_back(new Target(2, vec));
        //collective->setAgent(new MathAgent(i, vec, targets));
    }
    void setBeginActions(Collective* _collective, std::vector<double> _values)
    {
        double x0, sum = 0.0;
        VectorXd vec(1);
        int i = 1;
        for (auto iValue : _values)
        {
            sum += iValue;
            std::cout << "                  x1 = " << iValue << std::endl;
            vec << iValue;
            _collective->setAgent(new MathAgent(i, vec));
            i++;
        }
        std::cout << "Mean value:       xm = " << sum / _collective->getAgentCount() <<  std::endl;
    }
    void setBeginActions(Collective* _collective, int _numAgents)
    {
        double x0, sum = 0.0;
        VectorXd vec(1);
        srand(time(NULL));
        for (int i = 1; i <= _numAgents; i++)
        {
            x0 = ph::getRandomNumber(0, 100.0);
            sum += x0;
            std::cout << "                  x1 = " << x0 << std::endl;
            vec << x0;
            _collective->setAgent(new MathAgent(i, vec));
         }
        std::cout << "Mean value:       xm = " << sum / _collective->getAgentCount() <<  std::endl;
    }
    void setGraph()
    {
        if (graphType == "L") {
            graph = new LineGraph(1, collective->getAgentCount(), 6, 6);
        }
        if (graphType == "C") {
            std::cout << "Set circle graph: " << std::endl;
            graph = new CircleGraph(1, collective->getAgentCount());
        }
        if (graphType == "R") {
            std::cout << "Set circle graph: " << std::endl;
            graph = new RegularGraph(1, collective->getAgentCount(), 3);
        }
        if (graphType == "WS") {
            graph = new WattsStrogatzGraph(1, collective->getAgentCount(), 3, 0.15);
        }
        /*
        if (graphType == "WS-C") {
            std::cout << "Set Watts-Strogatz graph: " << std::endl;
            Graph* graph1 = new WattsStrogatzGraph(1, 20, 3, 0.15);
            std::cout << "  - graph 1" << std::endl;
            Graph* graph2 = new WattsStrogatzGraph(2, 20, 3, 0.15);
            std::cout << "  - graph 2" << std::endl;
            Graph* graph3 = new WattsStrogatzGraph(3, 20, 3, 0.15);
            std::cout << "  - graph 3" << std::endl;
            ClusterGraph* graph = new ClusterGraph(1, 5);
            graph->setCluster(graph1);
            graph->setCluster(graph2);
            graph->setCluster(graph3);
            graph->connected();

        }
        */
        graph->dump("", graphType + "-graph");
        std::cout << "(2) Graph is assigned: success" << std::endl;
        //sleep(50);
    }
    int numAgents;
    std::string graphType;
    TimeCounter* timecounter;
    Collective* collective;
    Graph* graph;
public:
    Manager(int _numAgents, std::string _graphType, TimeCounter* _timecounter) :
        numAgents(_numAgents), graphType(_graphType), timecounter(_timecounter)
    {

    }
    ~Manager()
    {
        delete collective;
        delete graph;
    }
    void computer(std::string _name, double _k, int _degree)
    {
    //! (1) Создаем набор агентов с начальными состояниями:        
        collective = new Collective;
        setBeginActions(collective, numAgents);
/*
        std::vector<double> values;
        values.push_back(75.7836);  // 1
        values.push_back(73.5893);  // 2
        values.push_back(25.8980);  // 3
        values.push_back(13.9531 ); // 4
        values.push_back(18.2806);  // 5
        values.push_back(39.4116);  // 6
        values.push_back(4.8952); // 7
        values.push_back(78.2220);  // 8
        values.push_back(29.7006);  // 9
        values.push_back(68.4622);  // 10
        setBeginActions(collective, values);
*/
/*
        std::vector<double> values;
        values.push_back(82.2291);  // 1
        values.push_back(96.1821);  // 2
        values.push_back(98.4802);  // 3
        values.push_back(26.6610); // 4
        values.push_back(84.2799);  // 5
        values.push_back(92.6908);  // 6
        values.push_back(50.3922); // 7
        values.push_back(98.3581);  // 8
        values.push_back(31.6263);  // 9
        values.push_back(29.1818);  // 10
        setBeginActions(collective, values);
*/
/*
        std::vector<double> values;
        values.push_back(87.4935);  // 1
        values.push_back(15.3874);  // 2
        values.push_back(83.5231);  // 3
        values.push_back(0.5554); // 4
        values.push_back(4.4404);  // 5
        values.push_back(19.9377);  // 6
        values.push_back(65.5721); // 7
        values.push_back(81.5546);  // 8
        values.push_back(37.2173);  // 9
        values.push_back(22.6264);  // 10
        setBeginActions(collective, values);
*/
/*
        std::vector<double> values;
        values.push_back(68.2821 );  // 1
        values.push_back(11.0752);  // 2
        values.push_back(40.8765);  // 3
        values.push_back(19.4433); // 4
        values.push_back( 2.2553);  // 5
        values.push_back(81.0450);  // 6
        values.push_back(64.6992); // 7
        values.push_back(98.5565);  // 8
        values.push_back(57.9150);  // 9
        values.push_back(0.9156);  // 10
        values.push_back(47.1053);  // 11
        values.push_back(17.6641);  // 12
        setBeginActions(collective, values);
*/
        std::cout << "(1) Collective is assigned: success" << std::endl;
    //! (2) Создаем граф:        
        setGraph();
        std::cout << "(2) Graph is assigned: success" << std::endl;
    //! (3) Создаем динамическую сеть:
        DynamicNetwork* network = new DynamicNetwork(timecounter, graph, collective);
        std::cout << "(3) Dynamic network is assigned: success" << std::endl;
    //! (4) Создаем модель:
        //SimplePairProtocol* protocol = new SimplePairProtocol();
        //GeometricMeanPairProtocol * protocol = new GeometricMeanPairProtocol();

        double sigma = _k * (collective->getMaxState() -  collective->getMinState()).norm() / collective->getAgentCount();
        //double sigma = 0.75 * 100.0 / collective->getAgentCount();
        //Connection* connection = new PairConnection();
        Connection* connection = new TriadicConnection(sigma, _degree);
        //Connection* connection = new FullyTriadicConnection(_degree);
        NonadditiveProtocol * protocol = new NonadditiveProtocol(connection);

        //TargetProtocol * protocol = new TargetProtocol();

        LinearModel* model = new LinearModel(network, protocol);        
        MatrixXd A(1, 1);  A << 1.0;
        MatrixXd B(1, 1);  B << 1.0;
        model->setEquation(std::pair(A,B));
        model->setDumpParameter("solve");
        model->setDumpParameter("weight");
        //model->setDumpParameter("desync");
        //model->setDumpParameter("order");
        std::cout << "(4) Model is assigned: success" << std::endl;
    //! (5) Выбор численной схемы и првоедение расчета:
        EulerScheme* scheme = new EulerScheme(model, "output/", "dump");
        scheme->solve(collective->getSystemVector());
        std::cout << "(5) Task is completed: success" << std::endl;
    //! (6) Вывод данных:
        model->dump("output/", graphType + std::to_string(numAgents) + "_" + _name);
        std::cout << "(6) Data output: success" << std::endl;

        delete network;
        delete scheme;
        delete model;
        delete collective;
        delete graph;
    }
};


int main(int argc, char *argv[])
{

    TimeCounter* timecounter = new TimeCounter;    
    //timecounter->setStepInterval(0.0, 2.8, 0.000028);
    timecounter->setStepInterval(0.0, 10000.0, 0.1);
    Manager* manager;
    //manager = new Manager(16, "C", timecounter);
    //manager->computer(std::to_string(1));

    //for (int n = 10; n <= 20; n++)
/*
    std::vector<double> degrees;
    degrees.push_back(-2);
    degrees.push_back(-4);
    degrees.push_back(-6);
    degrees.push_back(-8);
    degrees.push_back(-10);
    degrees.push_back(-15);
    degrees.push_back(-20);
    degrees.push_back(-25);
    degrees.push_back(-30);
    degrees.push_back(-35);
    degrees.push_back(-40);
    degrees.push_back(-100);
*/
    std::vector<double> sigma;
    for (int i = 0; i <= 30; i++)
    {
        sigma.push_back(0.05 * i);
    }
/*
    degrees.push_back(0.25);
    degrees.push_back(0.50);
    degrees.push_back(0.75);
    degrees.push_back(1.00);
    degrees.push_back(1.25);
    degrees.push_back(1.50);
    degrees.push_back(1.75);
    degrees.push_back(2.00);
    degrees.push_back(2.25);
    degrees.push_back(2.50);
    degrees.push_back(2.75);
    degrees.push_back(3.00);
*/

    manager = new Manager(10, "C", timecounter);
    manager->computer(std::to_string(3), 5.0, -2);
/*
    int n = 8;
    for (int i = 0; i < sigma.size(); i++)
    {
        manager = new Manager(n, "C", timecounter);
        //manager->computer(std::to_string(i + 1), 1.25, degrees[i]);
        manager->computer(std::to_string(i + 1), sigma[i], -4);

        //for (int i = 1; i <= 500; i++)
        //{
        //    manager->computer(std::to_string(i));
        //}

    }
*/
    std::cout << "Exit!" << std::endl;

    delete manager;
    return 0;

}

