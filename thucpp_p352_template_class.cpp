#include<iostream>
using namespace std; 
template<class T>
class Store{//目标是存储任意类型 
private:
	T item;
	bool have_value;
public:
	Store();//默认构造函数必须得写 
	void value_input(T x);
	T value_output();
	
}; 
template<class T>//这个每个定义前面都带
Store<T>::Store(){
	//我啥也不干 但得写出来？	
} 

template<class T>//这个每个定义前面都要带 
T Store<T>::value_output(){
	return item;//返回item的值 
}

template<class T>//这个每个定义前面都要带 
void Store<T>::value_input(T x){ //在类型和函数中间加上了模板类的说明 
	this->item=x;
	return;
}

int main(){
	//实例化int类 
	Store<int>  integer1;//定义Store<int>类的对象，此时Store<int>就是一个类了；
	int x;
	cin>>x;//输入存储数 
	integer1.value_input(x);
	cout<<integer1.value_output()<<endl;
	
	//实例化float类 
	Store<float> float1;//定义Store<float>类的对象，此时Store<float>就是一个类了；
	float y;
	cin>>y;//输入存储数 
	float1.value_input(y);
	cout<<float1.value_output();	
	return 0;
} 
