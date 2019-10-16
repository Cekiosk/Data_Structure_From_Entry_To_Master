#include<iostream>
#define DEFAULT_CAPACITY 3
using namespace std;

typedef int Rank ;

template<typename T>//就是一个模板./模板函数开始前的标识符 
class Vector{
protected://和private类似 继承时候有区别 
	Rank _size; int _capacity; T* _elem;//规模，容量，私有数组首地址/指针
	//void
public:
	Vector(int c=DEFAULT_CAPACITY,int s=0,T v=0);//我猜因为我也没有这个T的构造函数 不不不假设我设置T为int也不需要构造函数（是的！ 
	
};

template<typename T>//就是一个模板./模板函数开始前的标识符 //vector<T>相当于一个被T具象化的vector模板类 
Vector<T>::Vector(int c,int s,T v){//构造函数1 默认int c=DEFAULT_CAPACITY,int s=0,int v=0 这个默认只能写在类里 不可以在定义里 但记得注释 
	
		_elem = new T[_capacity=c];//int的话就是 int* point; point=new int(2); 
		for(_size=0;_size<s;_elem[_size++]=v){
			cout<<"now v is "<<v<<". now size is: "<<_size<<endl;
		}
		cout<<"finish !"<<endl;
	}

int main(){
	Vector<int> my_vec(3,6,1);
}
