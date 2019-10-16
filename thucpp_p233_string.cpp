#include<iostream> 
#include<string>
using namespace std;

int main(){
	string s1="i love ll";
	string s2="i love kk";
	s1.swap(s2);//交换两个字符串内容 
	s2.assign("ll is best in the world.");
	s2.append(" and I love her.");
	string s_add=s1+"."+s2;//+号连接符 
	cout<<s_add<<endl;
	cout<<s1.length()<<endl;//计算字符串长度 ，输出的是没有'/0'的 
	
	string s_getline1,s_getline2;
	getline(cin,s_getline1,',');//读取到分隔符之前所有string，如果没有第三个参数默认是回车
	getline(cin,s_getline2);//getline函数 
	
	int result = s_getline1.compare(s_getline2);//比较函数：本串小为负，本串大为正，相等为0  
	cout<<"compare result:"<<result<<endl;
	
	int occur_pos;//出现位置的变量 
	string s_search="ll";//需要先声明是string类才可以用find 
	
	occur_pos=s2.find("ll");//查找第一次出现的ll的位置 找不到返回-1 因为我换过俩的位置 才找不到ll的 

//	occur_pos=s_search.find(s1);//被搜索的在后面，必须放引用？ 
	cout<<occur_pos<<endl;//为什么是-1 
	
	string s_insert=s2.insert(occur_pos,"super ");//插入函数,插入到pos前面 
	cout<<s_insert<<endl;
	string s1_substr,s_assi,s_app;
	s1_substr=s1.substr(7,2); //substr 取pos开始的n个字符 
	cout<<s1_substr<<endl;
	
}
