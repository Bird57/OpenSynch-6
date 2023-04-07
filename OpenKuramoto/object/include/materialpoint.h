#ifndef MATERIALPOINT_H
#define MATERIALPOINT_H

struct MaterialPoint
{
    MaterialPoint();
    MaterialPoint(unsigned int _number, double _x);
    ~MaterialPoint();
    void setValue(double);
    void shiftValue(double);
    void setInstantVelocity(double);
    void shiftInstantVelocity(double);
    double getValue();
    double getInstantVelocity();
    unsigned int getNumber();
protected:
    unsigned int number_;
    double x_;
    double v_;
};

#endif // MATERIALPOINT_H
