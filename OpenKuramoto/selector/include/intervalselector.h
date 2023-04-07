#ifndef INTERVALSELECTOR_H
#define INTERVALSELECTOR_H

#include <iostream>
#include <fstream>
#include <vector>

#include "selector.h"

typedef std::pair<double, double> Intreval;

struct IntervalSelector
        : public Selector
{
    IntervalSelector();
    ~IntervalSelector();
    void setInterval(double _time_1, double _time_2);
    void dump(std::string _address, std::string _name);
    bool isTrue();
    bool select(double _time);
    Intreval* getPresentInterval();
private:
    bool flag_;
    bool isChange_;
    //unsigned int number_;
    Intreval* interval_;
    std::vector<Intreval> intervals_;
};

#endif // INTERVALSELECTOR_H
