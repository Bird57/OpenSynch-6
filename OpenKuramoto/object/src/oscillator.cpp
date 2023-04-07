#include "oscillator.h"

Oscillator::Oscillator(unsigned int _number, double _theta, double _omega) :
    MaterialPoint(_number, _theta), omega_(_omega)
{

}

void Oscillator::setSelfVelocity(double _omega)
{
    omega_ = _omega;
}
double Oscillator::getSelfFrequency()
{
    return omega_;
}

void Oscillator::setConnection(double _value, Oscillator* _oscillator)
{
    connections_[_oscillator] = new StaticEdge(this, _oscillator, _value);
}
void Oscillator::setConnection(Edge* _edge)
{
    connections_[_edge->getChildOscillator()] = _edge;
}
Edge* Oscillator::getConnection(Oscillator* _oscillator)
{
    auto search = connections_.find(_oscillator);
    if (search != connections_.end()) {
        return search->second;
    }
    else {
        return NULL;
    }
}
