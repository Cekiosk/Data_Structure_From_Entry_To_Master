#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int power2(int n);	//�ѵ�ʹ��һ�κ������� ������Ϊ2^(n) 
	int n=8 ;//����2^(n)����n 
	cout<<"the 2^"<<n<<" is "<<power2(n); 
	return 0;
} 

int power2(int n){
	int oe_flag=n & 1;//�ж���ż����flag ==1ʱ��nΪ���� ==0ʱ��nΪż�� (�պú�Ҫʹ�õ��Ǻ�)
	if(n==0){//ֹͣ/ƽ��/�ݹ������ 
		return 1;
	}
	else{//������� ��n!=0
		int n_k_1=(power2(n>>1));//�õ�n��ǰk01λ������ 
		return int(pow(n_k_1,2)) << oe_flag; //��ȡǰk-1������λ��n_(k-1) ֮�� �պó���2^oe_flag 
		//��Ϊpow����double Ҫǿת 
	}
}

