

#include "pavement.hpp"
#include "parkinglot.h"
template<class type>
void Pavement<type>::Print_pavement() {
	int i = 0, j = 0;
	int status;
	int h = 1;
	Print(0, h * 4 - 1, "便道状态",15);
	for (j = 0; j < 20; ) {
		for (i = 0; i < 7; i++) {

			if (j >= head && j < tail) status = 1;
			else status = 2;
			Print_Stall(i * 13, h * 4, status, j);
			if (j >= 20) break;
			j++;
		}
		h = h + 1;
	}
	int hn = h * 4 + 2;
	for (i = 0; i < 75; i++) {
		Print(i, hn, "-",15);
	}
	cout << endl;
	hn += 2;
}

template<class type>
Pavement<type>::Pavement(int i)
{
	head=0; tail=0; //将队列设置为空队列，head所指的位置为便道0，仅作为判断便道是否为满的条件,不停放车辆 
	maxsize=i<21?21:i;//设置便道的容量，最小为20
	this->qsize=0;//便道上实际停放的车辆数
	elements=new type[maxsize]; //给队列分配内存空间
	if(elements==NULL)//分配不成功
	{cout<<"out of memory"<<endl; exit(1);} 
}
template<class type>
bool Pavement<type>::Push(type &x)
{
	if(IsFull()) //便道已满，警告提示 
	{
		cout<<"便道已满，请寻找其他停车位，谢谢。"<<endl;
	    return false; 
    }
    tail=(tail+1)%maxsize; //尾指针+1
	elements[tail]=x;//车辆驶入便道 
	this->qsize++;//便道上停放的车辆数减1 
	return true; 
}


template<class type>
bool Pavement<type>::Pop(type &x)
{
	if(IsEmpty())//队已空，无车辆从便道进入停车场 
	{
		cout<<"便道上暂无车辆停放。"<<endl;
		return false;
	}
	head=(head+1)%maxsize;//头指针加1
	x=elements[head];//车辆驶出便道，即将进入停车场 
	this->qsize--;//便道上停放的车辆数减1 
	return true; 
}






