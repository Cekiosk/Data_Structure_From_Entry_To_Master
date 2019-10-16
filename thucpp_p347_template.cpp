#include<iostream>
using namespace std;
template<typename T>//template的尖括号可以接收 1.typename/class T 指明接收一个类型参数T(int/float/自定义等) 就使用上俩等效 
//这一整句是一个标识符，意味着接下来要接收一个函数模板作为参数，或者+class是接受一个类模板作为参数 
T abs (T x){//T当成int用
	return x<0?-x:x;//yes就是前面，no就是后面	
}

int main(){
	int n=-6;
	float d=-6.9;
	cout<<abs(n)<<endl;//abs自动从传入的n、d的类型推理出参数的类型，并且对模板函数实例化 
	cout<<abs(d)<<endl;//函数模板本身不生成目标代码，实例后才生成目标代码 
	return 0;
}
