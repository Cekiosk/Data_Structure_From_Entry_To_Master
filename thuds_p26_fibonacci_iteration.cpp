#include<iostream>
using namespace std;
/**测试用： 
    斐波那契数列Fibonacci
    一对小兔子两月具有繁殖能力，每月生一对
    经过月数：0 1 2 3 4 5 6  7 ...
    兔子对数： 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233，377，610，987，1597，2584，4181，6765，10946，17711，28657，46368
*/

//总结 两个算法的时间复杂度都是O(n) 都是常数级的空间 我用了3个课本那个 用了2个(用变量的变化前后表示三个变量的方法) 
int main(){
	int fib(int n);//我自己写的 
	int fib2(int n);//课本 
	int n;//求第n个fibonacci数 设第0个为0 第一个为1  
	cout<<"input you want to know the ___ th fibonacci number:(n>=0)"<<endl;//我把输入条件放宽了
	cin>>n;
	cout<<"1 . the "<<n<<"th fibonacci number is: "<<fib(n)<<endl;  
	cout<<"2 . the "<<n<<"th fibonacci number is: "<<fib2(n)<<endl;
	return 0; 
} 

int fib(int n){
	int fib_0=0, fib_ne1=1 ,fib_ne2=-1 ; //ne1 ne2是-1 -2 其实fib0不需要要 我写出来明确一些
	int prepre_fib,pre_fib,fib;//f(n-2),f(n-1),f(n)
	//初始化fib即fib(0)=fib(-1)[pre]+fib(-2)[prepre]
	pre_fib=fib_ne1;//初始化pre和prepre 
	prepre_fib=fib_ne2;
	//fib= fib_ne1+fib_ne2; //其实应该初始化两个pre 就行 我试试 
	
	for(int i=0;i<=n;i++){
		fib = pre_fib + prepre_fib; //f(n)=f(n-1)+f(n-2)
		prepre_fib=pre_fib;//f(n-2)=f(n-1)
		pre_fib=fib;//f(n-1)=f(n) 下一个相当于计算f(n+1)就用这行与上一行 
	} 
	return fib; 
}

int fib2(int n){//书本很简洁的改进方案 其实以下的n都可以写为i 因为是从i=0开始的 
	//初始化的位置 
	int g=0;//f(0) g最开始是f(i-1) 通过加上f(i-2)[更新前f]扩大 
	int f=1;//f(-1) f最开始是f(i-2) 通过被g(i)[更新后g]减去扩大 
	while(0 < n--){ //从n到 1可以 0不可以 共循环n次 while没必要用int 
		 g = g + f ;//g在此处是f(n-1)(右)与更新后的f(n)(左) 
		 f = g - f ;//f在此处是f(n-2)(右) 与更新后的f(n-1)(左)
		 //注意到关键在于 求f(n)=f(n-1)+f(n-2) 相当于:
		 //求f(n)[更新后的g]=f(n-1)[更新前的g]+f(n-2)[更新前的f];//g的更新是从f(n-1)[加上上一个f(n-2)] →f(n)  
		 //f(n-1)[更新后的f]=[f(n)[更新前的g]-f(n-2)[更新前的f] //f的更新是f(n-2) [被上一个f(n)减去]→f(n-1) (一个循环的过程)好好体会 
		 //什么时候 f(n-1)被更新的？ f(n-1)其实是更新前的g 与 更新后的f 所以两个变量足以 
	}//循环次数判断 有1项 循环一次 得f(1)=f(0)+f(-1) 大概明了了 第N项是f(n) 
	return g;	
}
