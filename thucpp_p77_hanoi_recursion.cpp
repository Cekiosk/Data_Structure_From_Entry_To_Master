#include<iostream>
using namespace std;
//我们把移动n>1个盘子的过程都叫做hanoi，把移动1个盘子的过程叫做move
//最终目标是，所有操作都变成移动一个盘子（之前移动的盘子会在下面当平地）

void move(char src, char dst){
	
	cout<<src<<"-->"<<dst<<endl; 

}

void hanoi(char src,char dst,char med,int disk_num){//这个函数即意味着，把disk_num个盘子，从src借助med移动到dst的总过程 
	int n=disk_num;
	if(n!=1){
		//如果有大于1个盘子要移动，都是要腾地方的
		hanoi(src,med,dst,n-1); //这里是S->M不是S->D 给我看清楚啊啊啊 
		move(src,dst);
		hanoi(med,dst,src,n-1);//就是 第一个位置担当什么 第二个位置担当什么 和叫什么名字无关 并且 在一次移动中这三步是重复的 
	}
	else{
		move(src,dst);//med输入了又咋样，我不用呀 
	}

} 
int main(){	//这个算法相当于在算法里已经做出汉诺塔规则的限制了 就没有其他限制 
	int disk_num;//盘子数量 
	//盘子数量靠我们来输入，盘子规定统一放在Src处，目标是Dst，三个盘子命名为A,B,C(初始src,med,dst) 
	cout<<"welcome to hanoi! please input the number of diskes:";
	cin>>disk_num;
	char src='a',med='b',dst='c';//给三个底座命名 
	hanoi(src,dst,med,disk_num);
	cout<<"finished!"<<endl;
	return 0;
}
