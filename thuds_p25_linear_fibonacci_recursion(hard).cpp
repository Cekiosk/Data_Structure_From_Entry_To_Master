#include<iostream>
using namespace std;
/**�����ã� 
    쳲���������Fibonacci
    һ��С�������¾��з�ֳ������ÿ����һ��
    ����������0 1 2 3 4 5 6  7 ...
    ���Ӷ����� 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233��377��610��987��1597��2584��4181��6765��10946��17711��28657��46368
*/

int main(){
	int fib(int n, int &pre_fib);//fibonacci���� 
	int n;//��n��fibonacci��(��1��ʼ)
	int prev_fib=0,fibo=0;//�����n-1��fibonacci�Ŀռ�;Ҳ���Բ��������Ĭ�ϵ� ;����һ������������ֵ�� 
	cout<<"input you want to know the ___ th fibonacci number:(n>=1)"; 
	cin>>n;
	if(n<=0){
		cout<<"illegal input! Please input an n>=1."<<endl;
		return 0;
	}
	fibo=fib(n,prev_fib);//�����ò�����ֵ�൱��:�Ұ����prev_n�����ú����ĸ�����ֱ���ð�(���޸�����ֵ)
	cout<<"the "<<n<<"th fibonacci number is: "<<fibo<<endl; 
	
	return 0;
}
//���������� int &a 

int fib(int n, int &pre_fib){//���룺Ҫ���㵽��n��fibֵ,fib(n-1)�Ĵ���ռ�
	//����ֵ�� prev_fib����һ���������������ƶ����� 

	if(n==1){//��ֹ���� n==1ʱ�� fib(1)=f(0)+fib(-1) 
		//�ݹ�� 
		//n==1��ʱ��preprefib�����f(n-2) =f(-1)=0 ����������preprefib�� ������Ҫ���� f(n-2) 
		//��Ϊf(1)��ֱ���趨�Ĳ���Ҫf(1-2)���� ��f(2)=f(1)+f(0) f(0)�����ﱻ��������prefib ��Ҫ����f(n-1)(f(1-1=0)) ������prefib��Ϊ��һ����ʵ����n-2 
		pre_fib=0;//f(0)=0
		//return����f(1)=1 �ش���f(2)=f(1)+f(0) 
		return 1;//f(1)=1
	}
	//���ϵ���ֹ������n==0,��ô����f(0)=0,��f(1)������� f(1)=f(0)+f(-1),��Ҫ��prev_fib��f(-1)�ֶ�����Ϊ1 ���ҵ������� 
	else{//n!=1 n==1�����һ�� 
		
		int prepre_fib;//����fib(n-2)��ֵ�����Ѵ˿ռ���Ϊ��fib(n-1,pre_fib)������һ��ֵfib(n-1-1)�ĸ����ռ�prefib����
		
		pre_fib=fib(n-1,prepre_fib); //����fib(n-1)��ֵ 
		
		return pre_fib+prepre_fib;//����fib(n)��ֵ 
	}
}//�ܽ� �鱾��˵�� prepre_fib��������f(n-2) ����ȷ�� 
