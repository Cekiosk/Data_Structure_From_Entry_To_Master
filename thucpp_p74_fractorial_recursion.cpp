//递归调用求阶乘 
#include<iostream>
using namespace std;

int factorial(int n){
	int fac; 
	cout<<"now n is "<<n<<endl;
	cout<<"now f-start is "<<fac<<endl; //注意它一直是0 不会变的 回带的过程来不到上面 
	if (n!=1){//记得if条件有括号  这里不可能是n-1给我好好想一下 
		fac=n*factorial(n-1);//递归的函数形式记得完全一致 而且事实上确实被拦着在这了 
//		cout<<"now f-end is "<<fac<<endl;//这里就没被执行到过 
//		return fac; //可以放在到 n!=1的最后 
	}	//if记得最开始就加括号 
	else{ 
		cout<<"reach the bottom"<<endl; 		
		return 1; //回归的部分 我已开始写成return 1  但是应该是return f 这个值可能不变 试试看 
		//此处另一种写法，只赋值，统一回归 
		//fac=1; 
	} 
		//else也要带括号啊啊啊！！！不然只有第一个在里面 一定会遇到它的 
	//但是到这按理说还没结束对吧 还有一个 如何返回第一层之后回归递推值的问题
	cout<<"now f-end is "<<fac<<endl;//这里就没被执行到过 
	return fac; //可以放在到 n!=1的最后 

}

int main(){
	//cout<<"test"<<endl; 
	int n;
	cout<<"input a n for factorial:"<<endl;
	cin>>n;
	cout<<"the factorial value:"<<factorial(n); //cout会计算y并输出 
	return 0;
	
} 
