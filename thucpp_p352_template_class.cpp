#include<iostream>
using namespace std; 
template<class T>
class Store{//Ŀ���Ǵ洢�������� 
private:
	T item;
	bool have_value;
public:
	Store();//Ĭ�Ϲ��캯�������д 
	void value_input(T x);
	T value_output();
	
}; 
template<class T>//���ÿ������ǰ�涼��
Store<T>::Store(){
	//��ɶҲ���� ����д������	
} 

template<class T>//���ÿ������ǰ�涼Ҫ�� 
T Store<T>::value_output(){
	return item;//����item��ֵ 
}

template<class T>//���ÿ������ǰ�涼Ҫ�� 
void Store<T>::value_input(T x){ //�����ͺͺ����м������ģ�����˵�� 
	this->item=x;
	return;
}

int main(){
	//ʵ����int�� 
	Store<int>  integer1;//����Store<int>��Ķ��󣬴�ʱStore<int>����һ�����ˣ�
	int x;
	cin>>x;//����洢�� 
	integer1.value_input(x);
	cout<<integer1.value_output()<<endl;
	
	//ʵ����float�� 
	Store<float> float1;//����Store<float>��Ķ��󣬴�ʱStore<float>����һ�����ˣ�
	float y;
	cin>>y;//����洢�� 
	float1.value_input(y);
	cout<<float1.value_output();	
	return 0;
} 
