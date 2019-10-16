#include<iostream>
//#include"point.h" //所以反而在正统里是这个不需要要 或者是把cpp挪过去？ 
#include"point.cpp"//这个是课本的失误，它加漏了 我要做个实验把它挪到.h的最后 不行 算了 
using namespace std;

//class Point{
//public:
//	Point(int x=0, int y=0) :x(x),y(y) { cout<<"construct function of point"<<endl;}//记得初始化变量之间是逗号 
//	~Point() {cout<<"destruct function of point"<<endl;}
//	void showPoint() const;
//private:
//	int x,y;
//};

//void Point::showPoint() const{
//	cout<<"The point you set is ("<<x<<","<<y<<")"<<endl; 
//} //为了搞文件结构换到别的文件了 

int main(){
	const Point mypoint(3,4);//试试是和不是常对象的时候是否可以调用常函数	
	mypoint.showPoint();
	return 0; 
}
