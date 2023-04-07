#ifndef MODEL_H
#define MODEL_H

#include "mathlist.h"
#include "timecounter.h"

struct Model
{
    TimeCounter* getTimeCounter();

    virtual void dump(std::string, std::string) = 0;
    virtual void setParameters() = 0;
    virtual void setEquation(std::pair<MatrixXd, MatrixXd> _pair) = 0;

    virtual VectorXd getEquationFunction(VectorXd&) = 0;

    MatrixXd getBasicMatrix();
    MatrixXd getControlMatrix();
protected:
    bool flagBasic_;
    bool flagControl_;
    MatrixXd basicmatrix_;
    MatrixXd controlmatrix_;

    TimeCounter* timecounter_;

    void setTimeCounter(TimeCounter* _timecounter);
};

#endif // MODEL_H
