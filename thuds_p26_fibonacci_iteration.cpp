#include<iostream>
using namespace std;
/**�����ã� 
    쳲���������Fibonacci
    һ��С�������¾��з�ֳ������ÿ����һ��
    ����������0 1 2 3 4 5 6  7 ...
    ���Ӷ����� 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233��377��610��987��1597��2584��4181��6765��10946��17711��28657��46368
*/

//�ܽ� �����㷨��ʱ�临�Ӷȶ���O(n) ���ǳ������Ŀռ� ������3���α��Ǹ� ����2��(�ñ����ı仯ǰ���ʾ���������ķ���) 
int main(){
	int fib(int n);//���Լ�д�� 
	int fib2(int n);//�α� 
	int n;//���n��fibonacci�� ���0��Ϊ0 ��һ��Ϊ1  
	cout<<"input you want to know the ___ th fibonacci number:(n>=0)"<<endl;//�Ұ����������ſ���
	cin>>n;
	cout<<"1 . the "<<n<<"th fibonacci number is: "<<fib(n)<<endl;  
	cout<<"2 . the "<<n<<"th fibonacci number is: "<<fib2(n)<<endl;
	return 0; 
} 

int fib(int n){
	int fib_0=0, fib_ne1=1 ,fib_ne2=-1 ; //ne1 ne2��-1 -2 ��ʵfib0����ҪҪ ��д������ȷһЩ
	int prepre_fib,pre_fib,fib;//f(n-2),f(n-1),f(n)
	//��ʼ��fib��fib(0)=fib(-1)[pre]+fib(-2)[prepre]
	pre_fib=fib_ne1;//��ʼ��pre��prepre 
	prepre_fib=fib_ne2;
	//fib= fib_ne1+fib_ne2; //��ʵӦ�ó�ʼ������pre ���� ������ 
	
	for(int i=0;i<=n;i++){
		fib = pre_fib + prepre_fib; //f(n)=f(n-1)+f(n-2)
		prepre_fib=pre_fib;//f(n-2)=f(n-1)
		pre_fib=fib;//f(n-1)=f(n) ��һ���൱�ڼ���f(n+1)������������һ�� 
	} 
	return fib; 
}

int fib2(int n){//�鱾�ܼ��ĸĽ����� ��ʵ���µ�n������дΪi ��Ϊ�Ǵ�i=0��ʼ�� 
	//��ʼ����λ�� 
	int g=0;//f(0) g�ʼ��f(i-1) ͨ������f(i-2)[����ǰf]���� 
	int f=1;//f(-1) f�ʼ��f(i-2) ͨ����g(i)[���º�g]��ȥ���� 
	while(0 < n--){ //��n�� 1���� 0������ ��ѭ��n�� whileû��Ҫ��int 
		 g = g + f ;//g�ڴ˴���f(n-1)(��)����º��f(n)(��) 
		 f = g - f ;//f�ڴ˴���f(n-2)(��) ����º��f(n-1)(��)
		 //ע�⵽�ؼ����� ��f(n)=f(n-1)+f(n-2) �൱��:
		 //��f(n)[���º��g]=f(n-1)[����ǰ��g]+f(n-2)[����ǰ��f];//g�ĸ����Ǵ�f(n-1)[������һ��f(n-2)] ��f(n)  
		 //f(n-1)[���º��f]=[f(n)[����ǰ��g]-f(n-2)[����ǰ��f] //f�ĸ�����f(n-2) [����һ��f(n)��ȥ]��f(n-1) (һ��ѭ���Ĺ���)�ú���� 
		 //ʲôʱ�� f(n-1)�����µģ� f(n-1)��ʵ�Ǹ���ǰ��g �� ���º��f ���������������� 
	}//ѭ�������ж� ��1�� ѭ��һ�� ��f(1)=f(0)+f(-1) ��������� ��N����f(n) 
	return g;	
}
