#include<iostream>
#include<vector> 
using namespace std;

int main(){
	unsigned n;
	cout<<"please input the size of the vector:"<<endl;
	cin>>n;
	vector<int> intarr(n);//可以在这个时候才确定数组的长度；(编译的时候不用确定)
	cout<<"please input "<<intarr.size()<<" intagers:"<<endl;//size函数可以取大小 
	for(int i=0;i<n;i++){
		cin>>intarr[i];
	}
	cout<<"the array is:"<<endl;
	for(int i=0;i<n;i++){
		cout<<intarr[i]<<" ";
	}	
	
	return 0;
}
