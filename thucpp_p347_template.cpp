#include<iostream>
using namespace std;
template<typename T>//template�ļ����ſ��Խ��� 1.typename/class T ָ������һ�����Ͳ���T(int/float/�Զ����) ��ʹ��������Ч 
//��һ������һ����ʶ������ζ�Ž�����Ҫ����һ������ģ����Ϊ����������+class�ǽ���һ����ģ����Ϊ���� 
T abs (T x){//T����int��
	return x<0?-x:x;//yes����ǰ�棬no���Ǻ���	
}

int main(){
	int n=-6;
	float d=-6.9;
	cout<<abs(n)<<endl;//abs�Զ��Ӵ����n��d��������������������ͣ����Ҷ�ģ�庯��ʵ���� 
	cout<<abs(d)<<endl;//����ģ�屾������Ŀ����룬ʵ���������Ŀ����� 
	return 0;
}
