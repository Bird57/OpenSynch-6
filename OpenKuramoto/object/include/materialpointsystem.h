#ifndef MATERIALPOINTSYSTEM_H
#define MATERIALPOINTSYSTEM_H

#include <iostream>

#include "timecounter.h"
#include "materialpoint.h"

struct MaterialPointSystem
{
    MaterialPointSystem()
    {
        number_ = 0;
        count_ = 0;
    }
    MaterialPointSystem(unsigned int _number, TimeCounter* _timecounter)
    {
        number_ = _number;
        timecounter_ = _timecounter;
        count_ = 0;
    }
    ~MaterialPointSystem()
    {
        delete timecounter_;
    }
    void dump(std::string _address, std::string _name);

    void setMaterialPoint(MaterialPoint* _object);

    unsigned int getNumber();

    unsigned int getCount();

    TimeCounter* getTimeCounter()
    {
        return timecounter_;
    }

    std::vector<MaterialPoint*>* getMaterialPoints();
protected:
    unsigned int number_;
    unsigned int count_;
    TimeCounter* timecounter_;
    std::vector<MaterialPoint*> points_;
};

#endif // MATERIALPOINTSYSTEM_H
