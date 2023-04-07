#include "timecounter.h"

TimeCounter::TimeCounter()
{
    count_ = 0;
    time_.push_back(0.0);
}
TimeCounter::~TimeCounter()
{
    time_.clear();
}
void TimeCounter::shift()
{
    count_++;
    if (count_ > time_.size())
    {
        count_--;
        std::cout << "Time counter is finished!!!" << std::endl;
    }
    delta_ = time_[count_ - 1] - time_[count_];
}
void TimeCounter::setTimeValue(double _time)
{
    time_.push_back(_time);
    //count_++;
}
void TimeCounter::dump(std::string _address, std::string _name)
{
    std::string fullAddress = _address + _name + ".txt";
    std::ofstream out(fullAddress, std::ios::out | std::ios::binary);
    int i = 0;
    for (auto &iTime : time_)
    {
        out << i << "  " << iTime << "\n";
        i++;
    }
    out.close();
}
void TimeCounter::setStepInterval(double _beginTime, double _endTime, double _stepTime)
{
    int iterations = static_cast<unsigned int>((_endTime - _beginTime) / _stepTime);
    for(int i = 0; i < iterations; i++)
    {
        setTimeValue(_beginTime + i * _stepTime);
    }
}
double TimeCounter::begin()
{
    return time_.front();
}
double TimeCounter::end()
{
    return time_.back();
}
double TimeCounter::getTimeValue()
{
    return time_[count_];
}
double TimeCounter::getTimeValue(unsigned int _count)
{
    if (_count < count_) {
        return time_[_count];
    }
    else
    {
        return NULL;
    }
}
unsigned int TimeCounter::getSize()
{
    return time_.size();
}
unsigned int TimeCounter::getCount()
{
    return count_;
}
