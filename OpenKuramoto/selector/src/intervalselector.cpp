#include "intervalselector.h"


IntervalSelector::IntervalSelector()
{
    flag_ = false;
}
IntervalSelector::~IntervalSelector()
{

}
void IntervalSelector::setInterval(double _time_1, double _time_2)
{
    intervals_.push_back(Intreval(_time_1, _time_2));
}
void IntervalSelector::dump(std::string _address, std::string _name)
{
    std::string fullAddress = _address + _name + ".txt";
    std::ofstream out(fullAddress, std::ios::out | std::ios::binary);
    int i = 0;
    for (auto &iInterval : intervals_)
    {
        out << i << "  " << iInterval.first << "  " << iInterval.second << "\n";
        i++;
    }
    out.close();
}
bool IntervalSelector::select(double _time)
{
    isChange_ = _time >= getPresentInterval()->first && _time <= getPresentInterval()->second;
    if (!isChange_) {
        if (_time >= intervals_.front().first && _time <= intervals_.back().second)
        {
            for (auto &iInterval : intervals_)
            {
                if (iInterval.first > _time)
                {
                    if (iInterval.second < _time)
                    {
                        flag_ = true;
                        interval_ = &iInterval;
                        break;
                    }
                }
                else
                {
                    flag_ = false;
                    break;
                }
            }
        }
    }
    return flag_;
}
bool IntervalSelector::isTrue()
{
    return flag_;
}
Intreval* IntervalSelector::getPresentInterval()
{
    return interval_;
}
