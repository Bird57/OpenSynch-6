#ifndef FINITEDIFFERENCEMETHOD_H
#define FINITEDIFFERENCEMETHOD_H

#include "model.h"

class FiniteDifferenceMethod
{
    void setDumpAddress( std::string _address,  std::string _name);
protected:
    Model* model_;
    TimeCounter* timecounter_;
    Model* getModel();    
public:
    //bool flag_;
    //bool flagData_;
    std::string address_;
    std::string name_;
    FiniteDifferenceMethod(Model*);
    FiniteDifferenceMethod(Model*, std::string, std::string);
    virtual ~FiniteDifferenceMethod();    
    virtual void solve(VectorXd* _X) = 0;

};


#endif // FINITEDIFFERENCEMETHOD_H
