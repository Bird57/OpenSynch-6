#include "materialpointsystem.h"


void MaterialPointSystem::dump(std::string _address, std::string _name)
{
    std::string fullAddress = _address + _name + ".txt";
    std::ofstream out(fullAddress, std::ios::out | std::ios::binary);
    int i = 0;
    for (auto &iOcsillator : points_)
    {
        out << iOcsillator->getNumber() << "  " << iOcsillator->getValue() << "  " << "\n";
        i++;
    }
    out.close();
}

void MaterialPointSystem::setMaterialPoint(MaterialPoint* _point)
{
    points_.push_back(_point);
    count_++;
}

unsigned int  MaterialPointSystem::getNumber()
{
    return number_;
}
unsigned int  MaterialPointSystem::getCount()
{
    return count_;
}

std::vector<MaterialPoint*>* MaterialPointSystem::getMaterialPoints()
{
    return &points_;
}
