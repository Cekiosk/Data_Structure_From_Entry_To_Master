#include<iostream>
#include<vector> 
using namespace std;

int main(){
	unsigned n;
	cout<<"please input the size of the vector:"<<endl;
	cin>>n;
	vector<int> intarr(n);//���������ʱ���ȷ������ĳ��ȣ�(�����ʱ����ȷ��)
	cout<<"please input "<<intarr.size()<<" intagers:"<<endl;//size��������ȡ��С 
	for(int i=0;i<n;i++){
		cin>>intarr[i];
	}
	cout<<"the array is:"<<endl;
	for(int i=0;i<n;i++){
		cout<<intarr[i]<<" ";
	}	
	
	return 0;
}
