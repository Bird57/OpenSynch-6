#include "oscillatorsystem.h"



OscillatorSystem::OscillatorSystem() :
    MaterialPointSystem()
{

}
OscillatorSystem::OscillatorSystem(unsigned int _number, TimeCounter* _timecounter) :
    MaterialPointSystem(_number, _timecounter)
{

}

void OscillatorSystem::copy(OscillatorSystem* copy)
{
    for (auto iOscillator : *copy->getOscilators())
    {
        setOscillator(new Oscillator());
        //oscillators_.push_back(new Oscillator());
        //objects_.push_back(oscillators_.back());
        *oscillators_.back() = *iOscillator;
        *points_.back() = *oscillators_.back();
    }
}
void OscillatorSystem::setOscillator(Oscillator* _oscillator)
{
    oscillators_.push_back(_oscillator);
    setMaterialPoint(oscillators_.back());
}
void OscillatorSystem::setConnections(double _value)
{
    for (auto iOscillator_1 : oscillators_)
    {
        for (auto iOscillator_2 : oscillators_)
        {
            iOscillator_1->setConnection(_value, iOscillator_2);
        }
    }
}
void OscillatorSystem::setConnections(std::vector<Edge*> _edges)
{
    for (auto iEdge : _edges)
    {
        iEdge->getParentOscillator()->setConnection(iEdge);
    }
}

std::vector<Oscillator*>* OscillatorSystem::getOscilators()
{
    return &oscillators_;
}
Oscillator* OscillatorSystem::getOscilator(unsigned int _number)
{
    return oscillators_[_number - 1];
}
