#include<iostream>
using namespace std;

void traverse( int* a, int n );//遍历数组 
void reverse( int *a, int n);//倒置 
void left_shift_recur(int *a ,int n,int p);//循环左移
void right_shift_recur(int *a ,int n,int p);//循环又移怎么写？ 互补数个左移 
int main(){
	int a[6]={0,1,2,3,4,5};
	//P3左移右移实验 
	//	reverse(a,6);
	left_shift_recur(a ,6,4);
	traverse(a,6);
	right_shift_recur(a,6,5);
	traverse(a,6);
	
	return 0;
} 

void traverse( int* a, int n ){
	cout<<"traverse the vector:"<<endl;
	for(int i=0; i<n ;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return;
}

void reverse( int *a, int n){
	int temp;
	for(int i=0,j=n-1;i<j;i++,j--){//for循环是一定要经历一次判断才进入的 
	//	cout<<"change";
		temp=a[i];a[i]=a[j];a[j]=temp;
	}
	return;
}

void left_shift_recur(int *a ,int n,int p){//循环左移，因为是手动输入的部分，所以需要输入控制 
	
	if(p<0||p>n){
		cout<<"error"<<endl;
	}
	else{
	
		reverse(a,p);
		reverse(a+p,n-p);
		reverse(a,n); 
	}
}

void right_shift_recur(int *a ,int n,int p){//循环右移 
	left_shift_recur(a,n,n-p);
}
