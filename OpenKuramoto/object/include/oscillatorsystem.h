#ifndef OSCILLATORSYSTEM_H
#define OSCILLATORSYSTEM_H

#include <vector>
#include <map>

#include "oscillator.h"
#include "materialpointsystem.h"



struct OscillatorSystem :
        public MaterialPointSystem
{
    OscillatorSystem();
    OscillatorSystem(unsigned int _number, TimeCounter* _timecounter);

    void copy(OscillatorSystem* copy);

    void setOscillator(Oscillator* _oscillator);

    void setConnections(double _value);
    void setConnections(std::vector<Edge*> _edges);

    Oscillator* getOscilator(unsigned int _number);
    std::vector<Oscillator*>* getOscilators();

private:    
    std::vector<Oscillator*> oscillators_;
};


#endif // OSCILLATORSYSTEM_H
