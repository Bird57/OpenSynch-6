#include "mathagent.h"

MathAgent::MathAgent(int _number, VectorXd _state) :
    Agent(_number, _state)
{

}
MathAgent::MathAgent(int _number, VectorXd _state, std::vector<Target*> targets_) :
    Agent(_number, _state, targets_)
{

}
MathAgent::~MathAgent()
{

}

void MathAgent::setPercept(VectorXd _percept)
{
    state_ = _percept;
    dim_ = state_.size();
}
void MathAgent::setControl(VectorXd _control)
{
    control_ = _control;
}

VectorXd MathAgent::getPercept()
{
    return state_;
}
VectorXd MathAgent::getAction()
{
    return state_;
}
VectorXd MathAgent::getControl()
{
    return control_;
}
