#include<iostream> 
#include<string>
using namespace std;

int main(){
	string s1="i love ll";
	string s2="i love kk";
	s1.swap(s2);//���������ַ������� 
	s2.assign("ll is best in the world.");
	s2.append(" and I love her.");
	string s_add=s1+"."+s2;//+�����ӷ� 
	cout<<s_add<<endl;
	cout<<s1.length()<<endl;//�����ַ������� ���������û��'/0'�� 
	
	string s_getline1,s_getline2;
	getline(cin,s_getline1,',');//��ȡ���ָ���֮ǰ����string�����û�е���������Ĭ���ǻس�
	getline(cin,s_getline2);//getline���� 
	
	int result = s_getline1.compare(s_getline2);//�ȽϺ���������СΪ����������Ϊ�������Ϊ0  
	cout<<"compare result:"<<result<<endl;
	
	int occur_pos;//����λ�õı��� 
	string s_search="ll";//��Ҫ��������string��ſ�����find 
	
	occur_pos=s2.find("ll");//���ҵ�һ�γ��ֵ�ll��λ�� �Ҳ�������-1 ��Ϊ�һ�������λ�� ���Ҳ���ll�� 

//	occur_pos=s_search.find(s1);//���������ں��棬��������ã� 
	cout<<occur_pos<<endl;//Ϊʲô��-1 
	
	string s_insert=s2.insert(occur_pos,"super ");//���뺯��,���뵽posǰ�� 
	cout<<s_insert<<endl;
	string s1_substr,s_assi,s_app;
	s1_substr=s1.substr(7,2); //substr ȡpos��ʼ��n���ַ� 
	cout<<s1_substr<<endl;
	
}
