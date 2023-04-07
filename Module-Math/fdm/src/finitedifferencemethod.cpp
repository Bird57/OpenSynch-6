#include "finitedifferencemethod.h"

FiniteDifferenceMethod::FiniteDifferenceMethod(Model* _model) :
    model_(_model)
{
    //flagData_= true;
    timecounter_ = getModel()->getTimeCounter();
}
FiniteDifferenceMethod::FiniteDifferenceMethod(Model* _model, std::string _address, std::string _name) :
    model_(_model)
{
    timecounter_ = getModel()->getTimeCounter();
    setDumpAddress(_address, _name);
}
FiniteDifferenceMethod::~FiniteDifferenceMethod()
{

}

void FiniteDifferenceMethod::setDumpAddress(std::string _address,  std::string _name)
{
    //flag_ = true;
    address_ = _address;
    name_ = _name;
}

Model* FiniteDifferenceMethod::getModel()
{
    return model_;
}

