#ifndef RUNGEKUTTASCHEME_H
#define RUNGEKUTTASCHEME_H

#include "finitedifferencemethod.h"


struct RungeKuttaScheme :
        public FiniteDifferenceMethod
{
    RungeKuttaScheme();
    ~RungeKuttaScheme();
    void solve(SynchronizationModel* _model, MaterialPointSystem* _system);
};


#endif // RUNGEKUTTASCHEME_H
