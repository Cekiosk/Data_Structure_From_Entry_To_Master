#include<iostream>
using namespace std;
//���ǰ��ƶ�n>1�����ӵĹ��̶�����hanoi�����ƶ�1�����ӵĹ��̽���move
//����Ŀ���ǣ����в���������ƶ�һ�����ӣ�֮ǰ�ƶ������ӻ������浱ƽ�أ�

void move(char src, char dst){
	
	cout<<src<<"-->"<<dst<<endl; 

}

void hanoi(char src,char dst,char med,int disk_num){//�����������ζ�ţ���disk_num�����ӣ���src����med�ƶ���dst���ܹ��� 
	int n=disk_num;
	if(n!=1){
		//����д���1������Ҫ�ƶ�������Ҫ�ڵط���
		hanoi(src,med,dst,n-1); //������S->M����S->D ���ҿ���������� 
		move(src,dst);
		hanoi(med,dst,src,n-1);//���� ��һ��λ�õ���ʲô �ڶ���λ�õ���ʲô �ͽ�ʲô�����޹� ���� ��һ���ƶ������������ظ��� 
	}
	else{
		move(src,dst);//med��������զ�����Ҳ���ѽ 
	}

} 
int main(){	//����㷨�൱�����㷨���Ѿ�������ŵ������������� ��û���������� 
	int disk_num;//�������� 
	//�������������������룬���ӹ涨ͳһ����Src����Ŀ����Dst��������������ΪA,B,C(��ʼsrc,med,dst) 
	cout<<"welcome to hanoi! please input the number of diskes:";
	cin>>disk_num;
	char src='a',med='b',dst='c';//�������������� 
	hanoi(src,dst,med,disk_num);
	cout<<"finished!"<<endl;
	return 0;
}
