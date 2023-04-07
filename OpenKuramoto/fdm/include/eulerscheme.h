#ifndef EULERSCHEME_H
#define EULERSCHEME_H

#include "finitedifferencemethod.h"


struct EulerScheme :
        public FiniteDifferenceMethod
{
    EulerScheme();
    ~EulerScheme();
    void solve(SynchronizationModel* _model, MaterialPointSystem* _system);
private:
};


#endif // EULERSCHEME_H
