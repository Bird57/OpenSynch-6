#ifndef MASMODEL_H
#define MASMODEL_H

#include "model.h"
#include "dynamicnetwork.h"
#include "protocol.h"

struct MASModel
        : public Model
{
    MASModel(DynamicNetwork* _network, Protocol* _protocol);
    ~MASModel();

//! Dump in file:
    void setDumpParameter(std::string _parameter);
    void setParameters();
    void dump(std::string _address, std::string _name);
    void clear();

//! Dual network:

protected:
    DynamicNetwork* getDynamicNetwork();
    Protocol* getProtocol();
private:    
    Protocol* protocol_;
    DynamicNetwork* network_;
    DynamicNetwork* dualnetwork_;

//! for setParameters:
    std::list<std::string> list_;
    std::vector<std::pair<double, double>> desync_;
    std::vector<std::pair<double, double>> order_;
    std::map<double, std::vector<std::pair<std::pair<int, int>, double>>> weights_;
    std::map<int, std::vector<std::pair<double, std::pair<VectorXd, VectorXd>>>> solve_;
};




#endif // MASMODEL_H
