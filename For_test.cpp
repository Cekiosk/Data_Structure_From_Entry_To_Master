#include<iostream>
using namespace std;

typedef struct{
	int size;//��ģ
	int capacity; 
	int *elem;//�������������� ������ 
}Vector;//���������Ľṹ�� �ǾͲ����ǵ���Ľṹ�� ����д�� 

int main(){
	/*
	int c=3;
	c<<=2;//д<<���� Ҫ<<= 
	cout<<c;
	*///2019.8.22����<<=������ 
	
	/*
	int *pint;
	pint=new int(1);
	cout<<*pint<<endl;
	delete pint;
	cout<<"DELETED int"<<endl; 
	 
	Vector *pV ; 
	pV=new Vector();
	delete pV;
	cout<<"DELETED pV"<<endl; 
	*///2019.8.22����new������ 
	
	/*
	int lo=1;
	int hi=5;
	while(lo<hi){
//		lo=lo++;//����ѭ�� why?��Ȥ 
		lo=++lo;
		cout<<lo;
	}*///2019.8.22����i=i++������ 
	
} 
