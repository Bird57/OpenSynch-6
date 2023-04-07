#ifndef EULERSCHEME_H
#define EULERSCHEME_H

#include "finitedifferencemethod.h"


struct EulerScheme :
        public FiniteDifferenceMethod
{
    EulerScheme(Model*);
    EulerScheme(Model*, std::string, std::string);
    ~EulerScheme();
    void solve(VectorXd* _X);
};


#endif // EULERSCHEME_H
