#ifndef SYNCHRONIZATIONMODEL_H
#define SYNCHRONIZATIONMODEL_H

#include <iostream>
#include <math.h>

#include "oscillatorsystem.h"
#include "timecounter.h"

class FiniteDifferenceMethod;

class SynchronizationModel
{
protected:
    bool flag_;
    std::string address_;
    std::string name_;
    OscillatorSystem* system_;
public:
    SynchronizationModel(OscillatorSystem* _system);
    virtual ~SynchronizationModel();

    virtual void compute() = 0;
    virtual double getSelfConsistentFunction(MaterialPoint*) = 0;

    void dump(std::string _address, std::string _name);
};



#endif // SYNCHRONIZATIONMODEL_H
