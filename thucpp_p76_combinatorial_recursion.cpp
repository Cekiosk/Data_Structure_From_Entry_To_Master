//�ݹ����������� 
#include<iostream>
using namespace std;

int com(int n,int k){
	int comSUM; //cpp�������ͺ�����������һ�� 
//	int com;
	if(!(n==k||k==0)){
		comSUM=com(n-1,k)+com(n-1,k-1);
		return comSUM;
	}
	else{
		return 1;
	}
}

int main(){
	int n,k;//�����ˣ�ѡ������
	//�������combinatorial number 
	cout<<"Input the number of combinations from n to k(n k)" ;
	cin>>n>>k;
	cout<<"The combination is"<<com(n,k); 
}
