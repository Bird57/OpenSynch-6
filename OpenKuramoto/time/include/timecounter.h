#ifndef TIMECOUNTER_H
#define TIMECOUNTER_H

#include <iostream>
#include <fstream>
#include <vector>

struct TimeCounter
{
    TimeCounter();
    ~TimeCounter();
//! Standart functions:   
    void reset()
    {
        count_ = 0;
    }
    void shift();
    void dump(std::string _address, std::string _name);
    double begin();
    double end();
//! Simple functions:
    void setTimeValue(double _time);
    void setStepInterval(double _beginTime, double _endTime, double _step);
    double getTimeValue();
    double getTimeValue(unsigned int _count);
    double getTimeStep()
    {
        if (count_ != 0) {
            return time_[count_] - time_[count_ - 1];
        }
        else
        {
            std::cout << "Step isn't exist" << std::endl;
            return NULL;
        }
    }
    unsigned int getSize();
    unsigned int getCount();
    bool isFinished()
    {
        return getCount() == getSize();
    }
private:
    double delta_;
    unsigned int count_;
    std::vector<double> time_;
};


#endif // TIMECOUNTER_H
