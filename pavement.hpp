#include<iostream>
#include <stdio.h>
using namespace std;
template<class type>
class abpave   //定义抽象队列类模板
{
	protected:
		int qsize;//便道上停放的车辆数 
	public:
		bool Impty()//判断便道上是否为空
		{return(qsize==0)?true:false;} 
		virtual bool Push(type &)=0;//将元素插入队尾
		virtual bool Pop(type &)=0;//从队头出队 
		virtual void Clear()=0;//清空队列 
};

template<class type>
class Pavement:public abpave<type>//循环队列 
{
	protected:
		type *elements; //存放车辆元素的数组
		int maxsize;//便道最大可容纳车辆数 
		int head;//队头
		int tail;//队尾 
	public:
		Pavement(int i=21);//构造函数，缺省值为21，最多可停放20辆汽车 
		~Pavement() {Clear();}//析构函数
		void getstate() { cout << "head=" << head << "  tail=" << tail << endl; }
		int gethead() { return head; };
		int gettail() { return tail; };
		void Clear() {delete []elements;}//清空队列
		bool IsFull(){return(tail+1)%maxsize==head;} //判断队列是否为满
		bool IsEmpty(){return head==tail;} //判断队列是否为空
		bool Push(type &);//入队
		bool Pop(type &);//出队 
		void outzero(){cout<<"head="<<head<<"所指的位置为便道0"<<endl;}
		void Print_pavement();
}; 
