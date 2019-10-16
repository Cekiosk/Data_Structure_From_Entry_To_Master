//递归调用求组合数 
#include<iostream>
using namespace std;

int com(int n,int k){
	int comSUM; //cpp变量名和函数名不可以一样 
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
	int n,k;//共几人，选出几人
	//组合数：combinatorial number 
	cout<<"Input the number of combinations from n to k(n k)" ;
	cin>>n>>k;
	cout<<"The combination is"<<com(n,k); 
}
