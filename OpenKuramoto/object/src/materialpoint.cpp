#include "materialpoint.h"

MaterialPoint::MaterialPoint()
{

}
MaterialPoint::MaterialPoint(unsigned int _number, double _x) :
    number_(_number), x_(_x)
{
    v_ = 0.0;
}
MaterialPoint::~MaterialPoint()
{

}
unsigned int MaterialPoint::getNumber()
{
    return number_;
}
void MaterialPoint::setValue(double _x)
{
    x_ = _x;
}
void MaterialPoint::setInstantVelocity(double _v)
{
    v_ = _v;
}
void MaterialPoint::shiftValue(double _dx)
{
    x_ += _dx;
}
void MaterialPoint::shiftInstantVelocity(double _dv)
{
    v_ += _dv;
}
double MaterialPoint::getValue()
{
    return x_;
}
double MaterialPoint::getInstantVelocity()
{
    return v_;
}

