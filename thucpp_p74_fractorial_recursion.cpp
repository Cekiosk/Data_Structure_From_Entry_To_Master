//�ݹ������׳� 
#include<iostream>
using namespace std;

int factorial(int n){
	int fac; 
	cout<<"now n is "<<n<<endl;
	cout<<"now f-start is "<<fac<<endl; //ע����һֱ��0 ������ �ش��Ĺ������������� 
	if (n!=1){//�ǵ�if����������  ���ﲻ������n-1���Һú���һ�� 
		fac=n*factorial(n-1);//�ݹ�ĺ�����ʽ�ǵ���ȫһ�� ������ʵ��ȷʵ������������ 
//		cout<<"now f-end is "<<fac<<endl;//�����û��ִ�е��� 
//		return fac; //���Է��ڵ� n!=1����� 
	}	//if�ǵ��ʼ�ͼ����� 
	else{ 
		cout<<"reach the bottom"<<endl; 		
		return 1; //�ع�Ĳ��� ���ѿ�ʼд��return 1  ����Ӧ����return f ���ֵ���ܲ��� ���Կ� 
		//�˴���һ��д����ֻ��ֵ��ͳһ�ع� 
		//fac=1; 
	} 
		//elseҲҪ�����Ű�������������Ȼֻ�е�һ�������� һ������������ 
	//���ǵ��ⰴ��˵��û�����԰� ����һ�� ��η��ص�һ��֮��ع����ֵ������
	cout<<"now f-end is "<<fac<<endl;//�����û��ִ�е��� 
	return fac; //���Է��ڵ� n!=1����� 

}

int main(){
	//cout<<"test"<<endl; 
	int n;
	cout<<"input a n for factorial:"<<endl;
	cin>>n;
	cout<<"the factorial value:"<<factorial(n); //cout�����y����� 
	return 0;
	
} 
