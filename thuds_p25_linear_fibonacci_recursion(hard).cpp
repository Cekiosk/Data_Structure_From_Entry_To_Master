#include<iostream>
using namespace std;
/**测试用： 
    斐波那契数列Fibonacci
    一对小兔子两月具有繁殖能力，每月生一对
    经过月数：0 1 2 3 4 5 6  7 ...
    兔子对数： 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233，377，610，987，1597，2584，4181，6765，10946，17711，28657，46368
*/

int main(){
	int fib(int n, int &pre_fib);//fibonacci函数 
	int n;//第n个fibonacci数(从1开始)
	int prev_fib=0,fibo=0;//保存第n-1个fibonacci的空间;也可以不给，设成默认的 ;还有一个保存计算出来值的 
	cout<<"input you want to know the ___ th fibonacci number:(n>=1)"; 
	cin>>n;
	if(n<=0){
		cout<<"illegal input! Please input an n>=1."<<endl;
		return 0;
	}
	fibo=fib(n,prev_fib);//给引用参数赋值相当于:我把这个prev_n交给该函数改个名字直接用吧(会修改内容值)
	cout<<"the "<<n<<"th fibonacci number is: "<<fibo<<endl; 
	
	return 0;
}
//引用声明是 int &a 

int fib(int n, int &pre_fib){//传入：要计算到第n个fib值,fib(n-1)的储存空间
	//传入值后 prev_fib就是一个整数变量的名称而已了 

	if(n==1){//终止条件 n==1时候 fib(1)=f(0)+fib(-1) 
		//递归基 
		//n==1的时候preprefib存的是f(n-2) =f(-1)=0 可是这里无preprefib了 即不需要计算 f(n-2) 
		//因为f(1)是直接设定的不需要f(1-2)来算 但f(2)=f(1)+f(0) f(0)是这里被传进来的prefib 需要计算f(n-1)(f(1-1=0)) 并填入prefib作为上一迭代实例的n-2 
		pre_fib=0;//f(0)=0
		//return的是f(1)=1 回传到f(2)=f(1)+f(0) 
		return 1;//f(1)=1
	}
	//书上的终止条件是n==0,那么返回f(0)=0,给f(1)做计算的 f(1)=f(0)+f(-1),把要给prev_fib的f(-1)手动设置为1 和我的无区别 
	else{//n!=1 n==1是最后一项 
		
		int prepre_fib;//保存fib(n-2)的值，并把此空间作为给fib(n-1,pre_fib)储存上一个值fib(n-1-1)的辅助空间prefib传入
		
		pre_fib=fib(n-1,prepre_fib); //保存fib(n-1)的值 
		
		return pre_fib+prepre_fib;//传回fib(n)的值 
	}
}//总结 书本的说法 prepre_fib帮助调阅f(n-2) 是正确的 
