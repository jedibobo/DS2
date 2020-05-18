//
//  ParkingLot.hpp
//  停车场
//
//  Created by Cedric on 2020/5/14.
//  Copyright © 2020 Cedric. All rights reserved.
//

#ifndef head_h
#define head_h

#include <stdio.h>
#include <iostream>
#include<windows.h>
#include<stdlib.h>

const unsigned maxSpace = 15;//最大停车数量

using namespace std;

template <typename T>
void Print(int x, int y, T output, int color);  //打印函数
template <typename T>
void Print_Stall(int x, int y, int status, T licence);  //打印车位函数

struct Car
{
    string Plate;
    int In ;
    int Out ;
};

template<class type>
struct Space//停车位
{
    type car;
    Space* next;
};

template<class type>
class ParkingLot//停车场栈
{
public:
    ParkingLot();
    ~ParkingLot() { Clear(); }
    void Clear();
    inline bool IsEmpty() { return (height == 0) ? true : false; }
    bool IsFull();
    bool Push(type& x);
    bool Pop(type& x);
    bool Pop1(type& x);//取出指定车
    type Top();
    //template <typename T>
    //void Print_Stall(int x, int y, int status, string licence);
    void Print_park();

protected:
    unsigned height;
    Space<type>* top;
};


template<class type>
class tempParkingLot//临时停车场栈
{
public:
    tempParkingLot();
    ~tempParkingLot() { Clear(); }
    void Clear();
    inline bool IsEmpty() { return (height == 0) ? true : false; }
    bool Push(type& x);
    bool Pop(type& x);
protected:
    unsigned height;
    Space<type>* top;
};



#endif /* ParkingLot_hpp */