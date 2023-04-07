#include "model.h"

TimeCounter* Model::getTimeCounter()
{
    return timecounter_;
}

MatrixXd Model::getBasicMatrix()
{
    return basicmatrix_;
}
MatrixXd Model::getControlMatrix()
{
    return controlmatrix_;
}

//protected:

void Model::setTimeCounter(TimeCounter* _timecounter)
{
    timecounter_ = _timecounter;
}
