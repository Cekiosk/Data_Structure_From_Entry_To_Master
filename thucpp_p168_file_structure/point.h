#include<iostream> //�õ�cout����Ҫ����� ��.h�����Ҳ���� �����Ҿ���ԭ����û����namespace std
using namespace std; //�������˾���ȱ��� 
//#include"point.cpp"//�����Է����⣡���������ǳ�����   
class Point{
public:
	Point(int x=0, int y=0) :x(x),y(y) {cout<<"construct function of point"<<endl;}//�ǵó�ʼ������֮���Ƕ��� 
	~Point() {cout<<"destruct function of point"<<endl;}
	void showPoint() const;
private:
	int x,y;
};

