#include "synchronizationmodel.h"

SynchronizationModel::SynchronizationModel(OscillatorSystem* _system) :
    system_(_system)
{
    flag_ = false;
}
SynchronizationModel::~SynchronizationModel()
{
    delete system_;
}
void SynchronizationModel::dump(std::string _address, std::string _name)
{
    flag_ = true;
    address_ = _address;
    name_ = _name;
}


