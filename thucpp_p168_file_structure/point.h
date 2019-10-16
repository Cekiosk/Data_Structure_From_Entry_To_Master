#include<iostream> //用到cout就需要加这个 在.h里这个也不行 但是我觉得原因是没有用namespace std
using namespace std; //啊可以了就是缺这个 
//#include"point.cpp"//不可以放在这！！！结果会非常诡异   
class Point{
public:
	Point(int x=0, int y=0) :x(x),y(y) {cout<<"construct function of point"<<endl;}//记得初始化变量之间是逗号 
	~Point() {cout<<"destruct function of point"<<endl;}
	void showPoint() const;
private:
	int x,y;
};

