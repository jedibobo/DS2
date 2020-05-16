#pragma once
#include <sstream>
#include <string>
#include <cmath>
#include "parkinglot.h"
#define parking_cost_per_hour 10
void str2int(int& int_temp, const std::string& string_temp)
{
    std::stringstream stream(string_temp);
    stream >> int_temp;
}

double parking_cost(Car p)
{
    double duration;
    double cost;
    cout << p.Out << "    " << p.In<<endl;
    duration = floor(p.Out-p.In) / 10000 + 1;
    cost = duration * parking_cost_per_hour;
    return cost;
}
