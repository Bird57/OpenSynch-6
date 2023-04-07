#ifndef CONNECTION_H
#define CONNECTION_H

#include <math.h>

struct Connection
{
    Connection()
    {

    }
    ~Connection()
    {

    }
    virtual double getFunction(double, double, double) = 0;
private:
};

struct PairConnection :
        public Connection
{
    PairConnection()
    {

    }
    double getFunction(double _x1, double _x2, double _x3)
    {
        return  1.0;
    }
private:
    double delta_;
    double n_;
    double sigma_;
};

struct TriadicConnection :
        public Connection
{
    TriadicConnection(double _delta, double _n) :
        delta_(_delta), n_(_n)
    {

    }
    double getFunction(double _x1, double _x2, double _x3)
    {
        sigma_ = abs(_x2 - _x3);
        //sigma_ = abs(abs(_x1 - _x2) - abs(_x1 - _x3));
        //sigma_ = abs(_x1 - _x3);
        return  1.0 / (pow(sigma_/delta_, n_) + 1.0);
        //return  1.0 / (pow(abs(_x1 - _x3)/delta_, n_) + 1.0) * 1.0 / (pow(abs(_x1 - _x2)/delta_, n_) + 1.0);
        //return  pow(sin(sigma_/delta_), 2.0);
    }
private:
    double delta_;
    double n_;
    double sigma_;
};


struct FullyTriadicConnection :
        public Connection
{
    FullyTriadicConnection(double _n) :
        n_(_n)
    {

    }
    double getFunction(double _x1, double _x2, double _x3)
    {
        sigma_ = 2.0 * abs(_x2 - _x3) / (abs(_x1 - _x2) + abs(_x1 - _x3));
        //sigma_ = 2.0 * abs(abs(_x1 - _x2) - abs(_x1 - _x3)) / (abs(_x1 - _x2) + abs(_x1 - _x3));
        return  (1.0 /(pow(sigma_, n_) + 1.0));
    }
private:
    double n_;
    double sigma_;
};




#endif // CONNECTION_H
