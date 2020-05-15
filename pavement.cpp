

#include "pavement.hpp"
#include "parkinglot.h"
template<class type>
void Pavement<type>::Print_pavement() {
	int i = 0, j = 0;
	int status;
	int h = 1;
	Print(0, h * 4 - 1, "���״̬",15);
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
	head=0; tail=0; //����������Ϊ�ն��У�head��ָ��λ��Ϊ���0������Ϊ�жϱ���Ƿ�Ϊ��������,��ͣ�ų��� 
	maxsize=i<21?21:i;//���ñ������������СΪ20
	this->qsize=0;//�����ʵ��ͣ�ŵĳ�����
	elements=new type[maxsize]; //�����з����ڴ�ռ�
	if(elements==NULL)//���䲻�ɹ�
	{cout<<"out of memory"<<endl; exit(1);} 
}
template<class type>
bool Pavement<type>::Push(type &x)
{
	if(IsFull()) //���������������ʾ 
	{
		cout<<"�����������Ѱ������ͣ��λ��лл��"<<endl;
	    return false; 
    }
    tail=(tail+1)%maxsize; //βָ��+1
	elements[tail]=x;//����ʻ���� 
	this->qsize++;//�����ͣ�ŵĳ�������1 
	return true; 
}


template<class type>
bool Pavement<type>::Pop(type &x)
{
	if(IsEmpty())//���ѿգ��޳����ӱ������ͣ���� 
	{
		cout<<"��������޳���ͣ�š�"<<endl;
		return false;
	}
	head=(head+1)%maxsize;//ͷָ���1
	x=elements[head];//����ʻ���������������ͣ���� 
	this->qsize--;//�����ͣ�ŵĳ�������1 
	return true; 
}






