#pragma once
#include <sstream>
#include <string>
#include <cmath>
#include "parkinglot.h"
#define parking_cost_per_hour 1
void str2int(int& int_temp, const std::string& string_temp)
{
    std::stringstream stream(string_temp);
    stream >> int_temp;
}

double parking_cost(Car p)
{
    int duration;
    double cost;
    cout << "离开时间："<<p.Out << "    进入时间：" << p.In<<endl;
    duration = p.Out-p.In;
    if (duration <= 1500)
    {
        duration = 0;//小于15min不收费
    }
    else
    {
        duration = floor(duration / 10000 + 1);
    }
    cout << "在停车场停留的时间为："<<duration<<"h"<<endl;
    cost = duration * parking_cost_per_hour;
    return cost;
}
