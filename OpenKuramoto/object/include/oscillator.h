#ifndef OSCILLATOR_H
#define OSCILLATOR_H

#include "materialpoint.h"
#include "staticedge.h"


struct Oscillator :
        public MaterialPoint
{
    Oscillator() :
        MaterialPoint()
    {

    }
    Oscillator(unsigned int _number, double _theta, double _omega);
    ~Oscillator();   

    void setSelfVelocity(double _omega);
    double getSelfFrequency();

    void setConnection(double _value, Oscillator* _oscillator);
    void setConnection(Edge* _edge);
    Edge* getConnection(Oscillator* _oscillator);    
private:    
    double omega_;
    std::map<Oscillator*, Edge*> connections_;
};

#endif // OSCILLATOR_H
