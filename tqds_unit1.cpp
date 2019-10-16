#include<iostream>
using namespace std;

void traverse( int* a, int n );//�������� 
void reverse( int *a, int n);//���� 
void left_shift_recur(int *a ,int n,int p);//ѭ������
void right_shift_recur(int *a ,int n,int p);//ѭ��������ôд�� ������������ 
int main(){
	int a[6]={0,1,2,3,4,5};
	//P3��������ʵ�� 
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
	for(int i=0,j=n-1;i<j;i++,j--){//forѭ����һ��Ҫ����һ���жϲŽ���� 
	//	cout<<"change";
		temp=a[i];a[i]=a[j];a[j]=temp;
	}
	return;
}

void left_shift_recur(int *a ,int n,int p){//ѭ�����ƣ���Ϊ���ֶ�����Ĳ��֣�������Ҫ������� 
	
	if(p<0||p>n){
		cout<<"error"<<endl;
	}
	else{
	
		reverse(a,p);
		reverse(a+p,n-p);
		reverse(a,n); 
	}
}

void right_shift_recur(int *a ,int n,int p){//ѭ������ 
	left_shift_recur(a,n,n-p);
}
