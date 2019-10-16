#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int power2(int n);	//难得使用一次函数声明 本函数为2^(n) 
	int n=8 ;//计算2^(n)的数n 
	cout<<"the 2^"<<n<<" is "<<power2(n); 
	return 0;
} 

int power2(int n){
	int oe_flag=n & 1;//判断奇偶数的flag ==1时候n为奇数 ==0时候n为偶数 (刚好和要使用的吻合)
	if(n==0){//停止/平凡/递归基条件 
		return 1;
	}
	else{//否则继续 即n!=0
		int n_k_1=(power2(n>>1));//得到n的前k01位二进制 
		return int(pow(n_k_1,2)) << oe_flag; //即取前k-1二进制位的n_(k-1) 之后 刚好乘上2^oe_flag 
		//因为pow返回double 要强转 
	}
}

