#include<iostream>
#define DEFAULT_CAPACITY 3
using namespace std;

typedef int Rank ;

template<typename T>//����һ��ģ��./ģ�庯����ʼǰ�ı�ʶ�� 
class Vector{
protected://��private���� �̳�ʱ�������� 
	Rank _size; int _capacity; T* _elem;//��ģ��������˽�������׵�ַ/ָ��
	//void
public:
	Vector(int c=DEFAULT_CAPACITY,int s=0,T v=0);//�Ҳ���Ϊ��Ҳû�����T�Ĺ��캯�� ����������������TΪintҲ����Ҫ���캯�����ǵģ� 
	
};

template<typename T>//����һ��ģ��./ģ�庯����ʼǰ�ı�ʶ�� //vector<T>�൱��һ����T���󻯵�vectorģ���� 
Vector<T>::Vector(int c,int s,T v){//���캯��1 Ĭ��int c=DEFAULT_CAPACITY,int s=0,int v=0 ���Ĭ��ֻ��д������ �������ڶ����� ���ǵ�ע�� 
	
		_elem = new T[_capacity=c];//int�Ļ����� int* point; point=new int(2); 
		for(_size=0;_size<s;_elem[_size++]=v){
			cout<<"now v is "<<v<<". now size is: "<<_size<<endl;
		}
		cout<<"finish !"<<endl;
	}

int main(){
	Vector<int> my_vec(3,6,1);
}
