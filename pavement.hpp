#include<iostream>
#include <stdio.h>
using namespace std;
template<class type>
class abpave   //������������ģ��
{
	protected:
		int qsize;//�����ͣ�ŵĳ����� 
	public:
		bool Impty()//�жϱ�����Ƿ�Ϊ��
		{return(qsize==0)?true:false;} 
		virtual bool Push(type &)=0;//��Ԫ�ز����β
		virtual bool Pop(type &)=0;//�Ӷ�ͷ���� 
		virtual void Clear()=0;//��ն��� 
};

template<class type>
class Pavement:public abpave<type>//ѭ������ 
{
	protected:
		type *elements; //��ų���Ԫ�ص�����
		int maxsize;//����������ɳ����� 
		int head;//��ͷ
		int tail;//��β 
	public:
		Pavement(int i=21);//���캯����ȱʡֵΪ21������ͣ��20������ 
		~Pavement() {Clear();}//��������
		void getstate() { cout << "head=" << head << "  tail=" << tail << endl; }
		int gethead() { return head; };
		int gettail() { return tail; };
		void Clear() {delete []elements;}//��ն���
		bool IsFull(){return(tail+1)%maxsize==head;} //�ж϶����Ƿ�Ϊ��
		bool IsEmpty(){return head==tail;} //�ж϶����Ƿ�Ϊ��
		bool Push(type &);//���
		bool Pop(type &);//���� 
		void outzero(){cout<<"head="<<head<<"��ָ��λ��Ϊ���0"<<endl;}
		void Print_pavement();
		void check();
}; 
