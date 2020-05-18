//
//  ParkingLot.cpp
//  停车场
//
//  Created by Cedric on 2020/5/14.
//  Copyright © 2020 Cedric. All rights reserved.
//

#include "parkinglot.h"

template <typename T>
void Print(int x, int y, T output, int color = 15) {
    COORD pos;
    HANDLE HAN_OUTPUT;
    pos.X = x;
    pos.Y = y;
    HAN_OUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(HAN_OUTPUT, color % 256);
    SetConsoleCursorPosition(HAN_OUTPUT, pos);
    cout << output;
}
template <typename T>
void Print_Stall(int x, int y, int status, T licence) {
    int color;
    char output = '=';
    int i;
    if (status == 0||status==2) {
        color = 2;
        if(status==2) Print(x + 2, y + 1, licence, color);  //此时为查询便道，该车位为空
        else if(status==0) Print(x + 2, y + 1, licence, color); //此时为查询车位，车位为空
    }
    else {
        color = 4;
        Print(x + 2, y + 1, licence, color);
    }
    for (i = x; i < x + 12; i++) {
        Print(i, y, output, color);
        if (i == x || i == x + 11) {
            Print(i, y + 1, output, color);
            Print(i, y + 2, output, color);
        }
        Print(i, y + 3, output, color);
    }

}


template<class type>
ParkingLot<type>::ParkingLot()
{
    height = 0;
    top = NULL;
}

template<class type>
void ParkingLot<type>::Clear()
{
    type x;
    while (Pop(x));
}

template<class type>
bool ParkingLot<type>::Push(type& x)
{
    Space<type>* p;
    if (height + 1 > maxSpace)//栈满
    {
        return false;
    }
    else if (top)//不是空栈
    {
        p = new Space<type>;
        p->car = x;
        p->next = top;
        top = p;
    }
    else//其他情况
    {
        top = new Space<type>;
        top->car = x;
        top->next = NULL;
    }
    height++;
    return true;
}

template<class type>
bool ParkingLot<type>::Pop(type& x)
{
    Space<type>* p;
    if (height)
    {
        x = top->car;
        p = top;
        top = top->next;
        delete p;
        height--;
        return true;
    }
    return false;
}

template<class type>
bool ParkingLot<type>::Pop1(type& x)
{
    type temp;
    bool is_in = true;
    bool check = true;
    tempParkingLot<type> tp;
    this->Pop(temp);
    while (temp.Plate != x.Plate && check == true)
    {
        tp.Push(temp);
        check = this->Pop(temp);
    }
    if (check == false)
    {
        Car falsecar;
        falsecar.Plate = "拥有该车牌号的车辆不在停车场！";
        x = falsecar;
        is_in = false;
        //delete falsecar;
    }
    else
    {
        x = temp;
    }
    while (tp.IsEmpty() != true)
    {
        tp.Pop(temp);
        this->Push(temp);
    }
    return is_in;
}



template<class type>
tempParkingLot<type>::tempParkingLot()
{
    height = 0;
    top = NULL;
}

template<class type>
void tempParkingLot<type>::Clear()
{
    type x;
    while (Pop(x));
}

template<class type>
bool tempParkingLot<type>::Push(type& x)
{
    Space<type>* p;
    if (top)//不是空栈
    {
        p = new Space<type>;
        p->car = x;
        p->next = top;
        top = p;
    }
    else//是空栈
    {
        top = new Space<type>;
        top->car = x;
        top->next = NULL;
    }
    height++;
    return true;
}

template<class type>
bool tempParkingLot<type>::Pop(type& x)
{
    Space<type>* p;
    if (height)
    {
        x = top->car;
        p = top;
        top = top->next;
        delete p;
        height--;
        return true;
    }
    return false;
}

template<class type>
void ParkingLot<type>::Print_park() {
    int i = 0, j = 0;
    

    type temp;
    tempParkingLot<type> tp;
    /*
    this->Pop(temp);
    while (temp.Plate != x.Plate)
    {
        tp.Push(temp);
        this->Pop(temp);
    }
    while (tp.IsEmpty() != true)
    {
        tp.Pop(temp);
        this->Push(temp);
    }
    */
    int h = 1;
    int state;
    int emmm=-1;   //检测有多少个空位
    string temp_Plate;
    Print(0, 3, "停车场状态", 15);
    for (i = 4; i < 8; i++) {
        //if(i!=5&&i!=6)
        Print(0, i, "#", 15);
        Print(2, i, "#", 15);
        if (i != 5 && i != 6) {
            Print(1, i, "#", 15);
        }
        Print(1, 5, "大", 15);
        Print(1, 6, "门", 15);
    }
    
    for (j = 0; j < maxSpace; ) {
        for (i = 0; i < 5; i++) {
            if (j >= maxSpace) break;
            j++;
            emmm++;
            if (emmm<15-height) {
                state = 0;
                //temp_Plate = emmm;
                Print_Stall(i * 13+4, h * 4, state, emmm);
                continue;
            }
            else {
                state = 1;
                this->Pop(temp);
                temp_Plate = temp.Plate;
                tp.Push(temp);
            }
            Print_Stall(i * 13+4, h * 4, state, temp_Plate);
        }
        h = h + 1;
    }
    int hn = h * 4 + 2;
    for (i = 0; i < 75; i++) {
        Print(i, hn, "-", 15);
    }
    cout << endl;
    //hn += 2;
    while (tp.IsEmpty() != true)
    {
        tp.Pop(temp);
        this->Push(temp);
    }

}




