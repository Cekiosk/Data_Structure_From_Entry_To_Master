#include<iostream>
//#include"point.h" //���Է�������ͳ�����������ҪҪ �����ǰ�cppŲ��ȥ�� 
#include"point.cpp"//����ǿα���ʧ������©�� ��Ҫ����ʵ�����Ų��.h����� ���� ���� 
using namespace std;

//class Point{
//public:
//	Point(int x=0, int y=0) :x(x),y(y) { cout<<"construct function of point"<<endl;}//�ǵó�ʼ������֮���Ƕ��� 
//	~Point() {cout<<"destruct function of point"<<endl;}
//	void showPoint() const;
//private:
//	int x,y;
//};

//void Point::showPoint() const{
//	cout<<"The point you set is ("<<x<<","<<y<<")"<<endl; 
//} //Ϊ�˸��ļ��ṹ��������ļ��� 

int main(){
	const Point mypoint(3,4);//�����ǺͲ��ǳ������ʱ���Ƿ���Ե��ó�����	
	mypoint.showPoint();
	return 0; 
}
