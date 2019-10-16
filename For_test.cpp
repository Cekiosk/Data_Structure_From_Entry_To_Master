#include<iostream>
using namespace std;

typedef struct{
	int size;//规模
	int capacity; 
	int *elem;//就是整数数组了 数据区 
}Vector;//定义向量的结构体 那就不考虑的类的结构了 单独写吧 

int main(){
	/*
	int c=3;
	c<<=2;//写<<不行 要<<= 
	cout<<c;
	*///2019.8.22关于<<=的讨论 
	
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
	*///2019.8.22关于new的讨论 
	
	/*
	int lo=1;
	int hi=5;
	while(lo<hi){
//		lo=lo++;//会死循环 why?有趣 
		lo=++lo;
		cout<<lo;
	}*///2019.8.22关于i=i++的讨论 
	
} 
