#ifndef FINITEDIFFERENCEMETHOD_H
#define FINITEDIFFERENCEMETHOD_H


#include <synchronizationmodel.h>

class FiniteDifferenceMethod
{
protected:
    TimeCounter* timecounter_;
public:
    FiniteDifferenceMethod();
    virtual ~FiniteDifferenceMethod();
    virtual void solve(SynchronizationModel*, MaterialPointSystem*) = 0;
};


#endif // FINITEDIFFERENCEMETHOD_H
