#include<iostream>
using namespace std;
#define DEFAULT_CAPACITY 2
#include   <stdlib.h>      
#include   <time.h>   

//�Ҽǵ�cpp����궨�峣��ʹ�õĶ� ����дһ��궨�� 
/*
struct vector{
}; *///cpp��������ʽ��typedef������
//����һ��rank��ʾ�ȵ� �Ҳ������� ��дһ�㲻������ 
typedef int T;//��ʾ�����������ͣ��˴���ʱ��int ���Ҫʵ�ֵĻ���Ҫʹ��ģ�� 

typedef struct{
	int size;//��ģ ������ʵ�����ֵ 
	int capacity; //�����������ռ�(��̬����Ĵ�С) 
	T *elem;//�������������� ������ 
}Vector;//���������Ľṹ�� �ǾͲ����ǵ���Ľṹ�� ����д�� 

int main(){
	Vector* construct_vector(Vector *this_v,int size=2,int capacity=DEFAULT_CAPACITY ,int elem_value=0);//��ͨ���� 
	Vector* construct_vector_copy(T const *A,int lo,int hi, Vector *this_v);//���ƹ��� 
	void assigned(Vector* v_assigned, Vector &v );//��ֵ 
	Vector* expand(Vector* this_v);//����   �����ڲ���ǰ���� 
	Vector* shrink(Vector* this_v);//����  ������ɾ�������� 
	T& get(Vector* this_v, int i);//�õ�Ԫ�� ���ҷ��ص������ÿ��Ը�ֵ 
	void swap(T &a, T &b);//����������������Ԫ�� 
	void permute(Vector* this_v);//���� 
	void output(Vector* this_v);
	void unsort(Vector* this_v,int lo,int hi);//�������� 
	int find(Vector* this_v,int lo ,int hi, T e);//���� ��[lo,hi)��e������Ԫ�ص���  �޼�����lo-1 
	int insert(Vector* this_v, int r, T const& e);//���ز���ֵ���� 
	int remove(Vector* this_v, int lo,int hi);// ɾ��[lo,hi) ����ɾ����Ԫ�ظ���hi - lo 
	int remove(Vector* this_v, int r);// ɾ��elem[r] ����elem[r]��ֵ 
	int deduplicate(Vector *this_v);//����ȥ�ء�����ȥ�������˼���Ԫ�� 
	int disordered(Vector *this_v); //�Ƿ������ж� �����򷵻�0 
	int uniquify( Vector *this_v );//����ȥ�أ��ж�ɾ���˼��� 
	int bin_search_B(T *A , int lo, int hi, T e); 
	void bubble_sort_A(T *A,int n);//���ð������ 
	void output_array(T *A, int n);//������飬Ҫ�Լ��ֶ� ����size 
	void bubble_sort_keshe(T r[], int n) ;//�����bubble sort 
	void merge( T *elem , int lo ,int hi ,int mi);//��һ�������������εĶ�·�鲢 
	void merge_sort(T *A, int lo , int hi);//��·�鲢���� 
//***************************����������	


	srand((unsigned int)(time(NULL))); //������������� 
	
	Vector *v1,*v2;//��������û����������ͦΣ�յ� 
	T A[6]={999,5,6,1,2,6};//���������Ƶ����� 
//****************�������취��ʹ�� 
//	v2=construct_vector(v1,3,6,9);//��ʼ���캯�� �ǵ���ʹ�ý���ɾ���� v1 size��3 
//	int size=v2->size; 
//	cout<<"test(return):"<<size<<endl;//�����return���ķ���
//	cout<<"test(return elme1):"<<v2->elem[1]<<endl;//�����return���ķ���
//************************************	

//****************��·�鲢�����ʹ��
	 
	output_array(A, 6); 
	cout<<"mergesort result: "<<endl; 
	merge_sort(A,0,6);//mi�ǹ���ε� 
	output_array(A, 6); 
		
//******************************************


//
////****************��·�鲢��ʹ��
//	 
//	output_array(A, 6); 
//	cout<<"merge result: "<<endl; 
//	merge(A,0,3,6);//mi�ǹ���ε� 
//	output_array(A, 6); 
//		
////******************************************

////****************ð������A��ʹ�� 
//	output_array(A, 6); 
//	cout<<"bubble sort result: "<<endl; 
//	bubble_sort_A(A,6);
//	bubble_sort_keshe(A,6);
//
//	output_array(A, 6); 	
////******************************************


////****************���ֲ���B��ʹ�� 
//	cout<<"bin search result: "<< bin_search_B(A, 0, 6, 6)<<endl; 
////******************************************
	
	
//****************���ƹ��취��ʹ�� 
	v1=construct_vector_copy(A,0,6,v2);//���ƹ��캯�� v2size��5 
	int size2=v1->size; 
//******************************************

//***************����ȥ�ص�Ӧ�� 
//	v1->capacity=6;//
//	output(v1);
//	cout<<"after uniquify "<<uniquify(v1)<<" element in the vector is remove."<<endl;//ʧ�ܻ᷵��lo-1 
//	output(v1);
//***********************


////***************�ж��Ƿ������Ӧ�� 
//	v1->capacity=6;//
//	output(v1);
//	cout<<"disordered ? "<<disordered(v1)<<endl;//ʧ�ܻ᷵��lo-1 
//	
////***********************


//
////***************����ȥ�ص�Ӧ�� 
//	v1->capacity=6;//
//	output(v1);
//
//	cout<<"after deduplicate "<<deduplicate(v1)<<" element in the vector is remove."<<endl;//ʧ�ܻ᷵��lo-1 
//	output(v1);
////***********************
//

////***************ɾ������Ԫ�ص�ʹ�� 
//	v1->capacity=6;//�������˵ļ��� 
//	output(v1);
//	int r=3;
//	cout<<"remove rank "<<r<<"in the vector .the remove element is:"<<remove(v1,r)<<endl;//ʧ�ܻ᷵��lo-1 
//	output(v1);
////***********************


////***************ɾ�������ʹ�� 
//	v1->capacity=6;//�������˵ļ��� 
//	output(v1);
//	int lo=1,hi=6;
//	cout<<"remove ["<<lo<<","<<hi<<")in the vector .the number of remove element is:"<<remove(v1,lo,hi)<<endl;//ʧ�ܻ᷵��lo-1 
//	output(v1);
////***********************


//
////***************�����ʹ�� 
//	v1->capacity=6;//�������˵ļ��� 
//	output(v1);
//	int e=999,r=3;
//	cout<<"Insert "<<e<<"in the position" <<r<<".the inserted rank is:"<<insert(v1,r,e)<<endl;//ʧ�ܻ᷵��lo-1 
//	output(v1);
////***********************


//
////***************������ҵ�ʹ�� 
//	int e=1;
//	cout<<"for find "<<e<<".the rank is:"<<find(v1,3,6,e)<<endl;//ʧ�ܻ᷵��lo-1 
//	
////***********************


//***************�������ҵ�ʹ�� 
//	output(v1);
//	unsort(v1,0,4);
//	output(v1);
//	unsort(v1,4,6);
//	output(v1);	

//***********************


//***************���ҵ�ʹ�� 
//	output(v1);
//	permute(v1);
//	output(v1);
//	permute(v1);
//	output(v1);	

//***********************

//****************��������Ԫ�ص�ֵ��ʹ�� 
//	int n1=1;
//	int n2=4;
//	
//	swap(get(v1,n1),get(v1,n2));
//	cout<<"I get ["<<n1<<"] element: "<< get(v1,n1) <<endl; //���������Ƿ�����ֵ�ı��� �����Ǹ��� 
//	cout<<"I get ["<<n2<<"] element: "<< get(v1,n2) <<endl; //���������Ƿ�����ֵ�ı��� �����Ǹ��� 

//***********************
	
//****************ȡԪ�� (�൱��[]��ʵ��)
//	int n=4;
//	//T get_elem=get(v1,n);//�������һ����ͨ�ĸ�ֵ 
//
//	T &elem=get(v1,n);//�����ó�ʼ������ 
//	elem =9;
//	cout<<"I get ["<<n<<"] element: "<< get(v1,n) <<endl; //���������Ƿ�����ֵ�ı��� �����Ǹ��� 
//******************************************

//************************���ݵ�ʹ�ã�ÿ��insert֮ǰ�������� �� 
//	v1->capacity=7;//�ֶ��������� 
//	cout<<"size:"<<size2<<endl;//�����**a���ķ��� ����ָ�뷨��Ȼ��覴�֮�����о��� 
//	cout<<"capacity:"<<v1->capacity<<endl;
//	expand(v1);
//********************************* 
	 
//************************���ݵ�ʹ�ã�ÿ��insert֮ǰ�������� �� 
//	v1->capacity=55;//�ֶ��������� 
//	cout<<"size:"<<size2<<endl;//�����**a���ķ��� ����ָ�뷨��Ȼ��覴�֮�����о��� 
//	cout<<"capacity:"<<v1->capacity<<endl;
//	shrink(v1);
//********************************* 
	
	 
//*********************��ֵ��ʹ�� 
//	Vector &v=*v1;//�����յ���Ӧ����һ��Ԫ�ؼ�ָ��ָ���Ԫ�� 
//	assigned(v2,v);//�Զ����ݵĸ�ֵ 
//**************************

	//************֮ǰdelete��������� �ͻ������ Ϊʲô�أ�-��Ϊ֮ǰ����û��������delete 
	delete[] v1->elem;
	delete v1; //ʹ�ý����ǵ�ɾ�� 

//	delete[] v2->elem;
//	delete v2; //ʹ�ý����ǵ�ɾ�� 

	cout<<"DELETED !"<<endl;
	return 0;
}


//=======��·�鲢
void merge( T *elem , int lo ,int mi ,int hi){//������д���� 
	void output_array(T *A, int n);//������飬Ҫ�Լ��ֶ� ����size 
	//����ǰ����������[lo,mi) [mi,hi)�ĳ���
	int lb=mi-lo; 
	int lc=hi-mi; 
	//�Ȱ��ţ�������ԭ�������[lo,hi)��Ϊ A �� ǰ��ηŽ��µ�ַB  �����θ������� C(���ǲ��˵�)
	//С���ɣ����ַ�����һ�����е�ʱ��Ҫ�������ֶζ��ӵ�һ���������һ�����Ǻ�����Զ���ᱻ���ǵģ��Ϳ����ý�ȡ�� 


	T *A =elem+lo ;//���鱾����һ�������ĵ�ַ �ǵ�ַ��ֵ�ɣ� 
	
	T *B =new T[lb];//new������Ҳ����Ҫ����С�ģ����ǿ�����Ԥ����/����ִ�е���֮����Ȼ��Ҫ�µĿռ䣬�Ǳ����������ⶫ����ԭ�� 
	//���ʱ���Ѿ�������ָ��޽ӽض��� ֱ�Ӹ���ֵ����
	for(int i=0; i<lb ;B[i]=A[i++]);//���ƹ��̣�A�Ѿ���lo���ضϺ���
	
	T *C =elem+mi;
//test
	cout<<"A: ";
	output_array(A,6);
//test
	cout<<"B: ";
	output_array(B,lb);
	//test
	cout<<"C: ";
	output_array(C,lc);

	//A,B,C���źý����������·ѡ�񻷽�
	//�ǵ�lc���ȵ��������һ����lc-1����kc�����ֵ����lc-1 
	//ֹͣ�����ǣ���B����kb<lb ���� C���� kc<lc ��Ҫ���� ����Ҫ�������������ļ�¼�� ka kb kc 
	for(int ka=0,kb=0,kc=0; (kb<lb||kc<lc);){//for�ĵڶ��������ú�whileһ�����ǵ�Ϊ1ʱ����� ,��Ȼ�������ղ��� ������Ҫ�����ֺ� 
		//װ��B�������� (B���� && (cû�� || B[kb]<=C[kc])) //�������С���� 
		if(kb<lb&& ( !(kc<lc) || B[kb]<=C[kc] )){
			A[ka++]=B[kb++];
		}
		//װ��Cͬ�� 
		
		if(kc<lc&& ( !(kb<lb) || B[kb]>C[kc] )){
		//test  
		//else{//�ƺ���elseЧ��Ҳ��һ����,��д���������� 
			A[ka++]=C[kc++];
		}
	}//for
	output_array(A, 6); 
	delete[] B;//ɾ����ʱ������B 

	return;	
	}
 
//========�����㷨 

void merge_sort(T *A, int lo , int hi){//��·�鲢���� 
	if(hi-lo<2){//��ʵ�� hi-lo==1 �ݹ�� 
		return;//���ص�Ԫ�أ���ʲôҲ����Ҫ�Ե�Ԫ���� 
	}
	else{ 
	int mi = (lo+hi)>>1;
	merge_sort(A,lo,mi);merge_sort(A,mi,hi); //�����ź��������������
	merge(A,lo,mi,hi);//������������������һ���������
	return;//��ͨ�������
	} 
}

void bubble_sort_keshe(T r[], int n) {  //���ݽṹ����ð������ 
	int change=0,move=0,vs=0; 
    int i= n -1;  //��ʼʱ,���λ�ñ��ֲ���  
    while ( i> 0) {   //iһ�����С��Ϊʲô 
        int pos= 0; //ÿ�˿�ʼʱ,�޼�¼����  
        for (int j= 0; j< i; j++,vs++)  
            if (r[j]> r[j+1]) {  
                pos= j; //��¼������λ��   
                swap(r[j],r[j+1]);
                change++;                
            }   
        i= pos; //Ϊ��һ��������׼��  
     }
     
	move=change*3;
	cout<<"ð����������ˣ�"<<endl;
    cout<<"�ƶ�����:"<<move<<endl;
	cout<<"�Ƚϴ���:"<<vs<<endl;
}    

void bubble_sort_A(T *A,int n){//�����㷨��Ҫͬʱ�������鳤��  ,���Ǵ���������������������ã��㷨Ϊ�������û��ô�鷳 
	bool sorted=false; //Ĭ��Ϊ������ȷ����Ȼ����ȥ; ��ȥ������Ϊ��ȷ 
	while(!sorted){
		sorted=true;
		for(int i=1; i<n ;i++){//ÿ�ֶ�ɨ���ȥ��һ�����ֵ��ȫ�� 
			if (A[i]<A[i-1]){
				swap(A[i],A[i-1]);
				sorted=false;
			}
		}
		n--;//���ֵ�϶��Ѿ����Ϻ��ʵ�ֵ�ˣ������ð�ݵĺ��� 
	}
} 
 
//============== 

//========�����㷨

int bin_search_B(T *A , int lo, int hi, T e){//�������������ط�Χ�����ض�Ӧ����/-1 
	int mid;
	while((hi-lo)>1){
		mid = (hi+lo)>>1;
//		(A[mid]<e)? hi=mid : lo=mid;//��һ�д���������ʽд���� 
//		(A[mid]>e)? hi=mid : lo=mid; //���� 
		(A[mid]>=e)? hi=mid : lo=mid;  //���԰ѵ��ڵ�����ŵ�[lo,mi)��  Ϊʲô���ȡhiҲ���ԣ���Ϊ������������mid�������ƽ���hi-1Ȼ��ͣ�£���ʱ��lo��hi-2��Ȼ�������� 
		
	}//��Ϊ�����������������㷨 ���� 
	cout<<A[lo]<<endl; 
//	return (e==A[lo])? lo : -1; //����	
	return (e==A[hi])? hi : -1; //������ڷŵ�[lo,mi) ������� �ǿ��Ե� ֻ��˵ȡhi�����������̶��Բ�̫�淶 
} 
//============== 
//���ȵù����ʵ����һ�� ���ǲ���û������ �������Ķ�������һ����������һ��������˳��� ��������ֻ��Ҫ����1�� 
Vector* construct_vector(Vector *this_v,int size=2,int capacity =DEFAULT_CAPACITY ,int elem_value=0){//��return������Ӱ�� 
	cout<<"start construction !"<<endl;//������Ҳû��ȡָ���ֵŶ 
	this_v=new Vector();//Vector* = new vector() ���ȸ�thisvһ��ʵ����vector�ռ� �ɹ��� �ǲ���Ҫ��������ô�������ռ�� 
	this_v->capacity=capacity;
	this_v->size=size; 
	this_v->elem = new T[capacity];	//�൱��T*=new T[] ���� this_v��δ����ʼ�� 
	for(int i=0;i<size;i++){
		this_v->elem[i]=elem_value;
		cout<<"now v is "<<this_v->elem[i]<<". now size is: "<<this_v->size<<endl;
	}
//	delete[] this_v->elem;//******delete ������ �Ͳ�������� 
//	delete this_v; //ʹ�ý����ǵ�ɾ�� 
	cout<<"finish !"<<endl;//��һ�������ھͿ��� ���ھͲ��У� 
	return this_v; 
} 	//	����Ǵ�����ֱ���޸� Ҳ����returnָ�룿 
Vector* construct_vector_copy(T const *A,int lo,int hi, Vector *this_v) {//������һ�������ʼ���Ĺ��캯�� copy����A�����A[lo,hi)������������ 
	cout<<"start copy construction !"<<endl;
	int capacity=2*(hi-lo);//������һ�ֹ涨 �涨������Ϊ2*(hi-lo) �Ե�!��ΪҪ����չ�ռ� 

	this_v=new Vector();//Vector* = new vector() ���ȸ�thisvһ��ʵ����vector�ռ� �ɹ��� �ǲ���Ҫ��������ô��Ŀռ�����vector[c]�� 
	this_v->elem = new T[capacity];//��������ռ� 
	//ELEMҲֻ����һ��ָ�� Ҫ����� 
	this_v->capacity=capacity;
//	this_v->size=size; size���Ǹ�ֵ�� ������lo��ֵ�ۼӵ�
	this_v->size=0;//�ʼ��ֵǰsize��0
//	int size=0; 
	while(lo<hi){//lo��hi-1��ʱ�������һ�� 
		cout<<"now Alo is "<<A[lo]<<". ";//ͦ������ �ղ�զ�� 
		this_v->elem[this_v->size++]=A[lo++]; //�����Ժ��ȸ�ֵ ��++ ��i++��i�Ȳ��Լӣ����������Լ� ��˴˴��൱�����һ�α�ִ�еĸ�ֵ��hi-1 
		//���Ƶ���elem��[0,hi-lo) 
//		size=size++;
		//lo=lo+1;//��ʾ��ǰ�Ļ���-1 
		cout<<"now v is "<<this_v->elem[(this_v->size-1)]<<". now rank is: "<<(this_v->size-1)<<". now size is: "<<this_v->size<<endl;//size���������Ԫ�ظ��� ������ȴ�1 
	}//ѭ�������ж�hi-lo�� 
//	this_v->size=size;��һ���������ķ����ڱ���size�Ͼ�û���� 
	cout<<"finish !"<<endl;
	return this_v;
}//���������캯���漰new������ָ�� 

void assigned(Vector* v_assigned, Vector &v ){//�Ҳ�����ʽ�� ����Ҫ��ֵǰ����*ָ�� 
	cout<<"start assign !"<<endl;
	if(v_assigned){//ֵ���� �����ͷ� ���ò�������->���� 
		delete[] v_assigned->elem;//�ͷ�ԭ������ Ϊʲô��ֱ��ȫɾ���� ���������ȫɾ ���Ǳ�ʼ����ͬһ�� �ޱ�Ҫ 
		delete v_assigned; //��Ҫ��copy�������ҵĶ�����ȫ�Ǵ����������� ĳ�취�ˣ����Ҷ����ǹ��캯����һ�֣�
		//����ҵ� ���Ʋ������º���զд ����һ��ָ���������ݵ�ָ�����ȡֵ���� ������û������� 
	} 
	cout<<"v size:"<<v.size<<endl;
	cout<<"v elme3:"<<v.elem[3]<<endl;
	v_assigned=construct_vector_copy(v.elem,0,v.size,v_assigned) ;//ԭ������Ҳ���з���ֵ���� 
	cout<<"END assign copy!"<<endl;//�ҵĸ�ֵ����Ĭ��ֻ�����������c ��̫���� �������� ���������Ѿ����Ǹ���˼�� ���ҵ�assign���Զ����ݵģ� 
	return;
	 
}//���˾�����ʵ�� �������� 

Vector* expand(Vector* this_v){//���� 
//	int size=this_v->size;
//	int capacity=this_v->capacity;//����������������ã�
 	int& size = this_v->size; 
	int& capacity = this_v->capacity ; 
	cout<<"initial capacity is:"<<capacity<<endl;
	if(size<capacity) {cout<<"still enough!"<<endl; return this_v;} //����û�� ��Ȼ�ż��� 
	
	cout<<"overflow! start expand !"<<endl;
	if(capacity<DEFAULT_CAPACITY) capacity=DEFAULT_CAPACITY;//ע�⣬��Ҫ���µ�ֻ�������� elme
	T* old_elem = this_v->elem;
	this_v->elem=new T[capacity<<=1];//��һ����������¿ռ� ע�������capacity�仯��elem��Ӱ�� ��Ȼ��һ�������� ���������� 
	//�����Ժ�͹�������Ӧ���Ǵ�����ǰ�ļ�鱣֤�� 
	cout<<"now new capacity is:"<<capacity<<endl;
	cout<<"now new capacity is:"<<this_v->capacity<<endl;
	for(int i=0;i<size;i++){ //��ʵ�����η��� 
		this_v->elem[i]=old_elem[i];//�൱�ڱ��ṹ��ָ������������� �������޹� ɾ��ԭ�������ͺ��� 
	}
	//�һ�û���ֶ��İѲ���ֵ���� ������;ȫ����Ҳ�У�����̫���� 
//	int size=this_v->size;
//	int capacity=this_v->capacity;
	delete[] old_elem;
	cout<<"EXPAND SUCCESS AND DELETE THE OLD MEMORY !"<<endl;
	cout<<"now new capacity is:"<<this_v->capacity<<". and size is :"<<this_v->size<<endl;
	return this_v;//˵�������������Ҳ����Ϊû�иı�ԭֵ ������ 
}


Vector* shrink(Vector* this_v){//����  
//	int size=this_v->size;
//	int capacity=this_v->capacity;//����������������ã�
 	int& size = this_v->size; 
	int& capacity = this_v->capacity ; 
	cout<<"initial capacity is:"<<capacity<<endl;

	if(capacity<DEFAULT_CAPACITY<<1) {cout<<"still reach default!"<<endl; return this_v;} //��֤�����Ժ󲻻�С��Ĭ������ 

	if(size<<2>capacity) {cout<<"dont need shrink!"<<endl; return this_v;} //size >1/4capacity ������ 
	
	cout<<"underflow! start shrink !"<<endl;

	T* old_elem = this_v->elem;// ָ��=ָ�� ��ʵ���������ļ޽� 
	this_v->elem=new T[capacity>>=1];//��һ����С1/2���¿ռ� ע�������capacity�仯��elem��Ӱ�� ��Ȼ��һ�������� ���������� 

	cout<<"now new capacity is:"<<capacity<<endl;
	cout<<"now new capacity is:"<<this_v->capacity<<endl;
	for(int i=0;i<size;i++){ //��ʵ�����η��� 
		this_v->elem[i]=old_elem[i];//�൱�ڱ��ṹ��ָ������������� �������޹� ɾ��ԭ�������ͺ��� 
	}
	//�һ�û���ֶ��İѲ���ֵ���� ������;ȫ����Ҳ�У�����̫���� 
//	int size=this_v->size;
//	int capacity=this_v->capacity;
	delete[] old_elem;
	cout<<"SHRINK SUCCESS AND DELETE THE OLD MEMORY !"<<endl;
	cout<<"now new capacity is:"<<this_v->capacity<<". and size is :"<<this_v->size<<endl;
	return this_v;//˵�������������Ҳ����Ϊû�иı�ԭֵ ������ 
}

T& get(Vector* this_v, int i){ //�������� �������㴫�����Ķ�����ı��� ��������Ϊ ��ֵ���丳ֵ 
	return this_v->elem[i];
}

void swap(T &a, T &b){
	T t=a;
	a=b;
	b=t;
}

void permute(Vector* this_v){
	for(int i=(this_v->size-1);i>0;i--){//elem[0]�ǲ���Ҫ����ѭ���� �Ѿ��������� 
		swap(get(this_v,i),get(this_v,rand()%i));
	} 
}

void unsort(Vector* this_v,int lo,int hi){//�鱾������ضϷ� 
	cout<<"now unsort elem["<<lo<<","<<hi<<")!"<<endl; 
	T* new_elem= this_v->elem+lo;//���׵�ַ��0 �ڵ�ַ��0+lo�ĵط�����һ��ָ�� �Դ�ָ��Ĳ����൱����ԭ�������Ͻس����������� 
	//�һ�������һ��ȡ��this_v����Ĳ����� 
	for(int i=(hi-lo-1);i>0;i--){//����ѭ������������ ���һ��ֵ��new_v[hi-lo-1] //elem[0]�ǲ���Ҫ����ѭ���� �Ѿ��������� 
		swap(new_elem[i],new_elem[rand()%i]);//�а� ���տα��Ļ�������swap��������elemֵ ��this v�޹� ��this_v�Ľ����ڵ�һ����ʽ 
	} //ע�⵽ unsort��Ϊ����˲���ָ����� ���ʵĶ���ȷʵ��permute�ǲ�һ���� 
}


void output(Vector* this_v){
	cout<<" now size is: "<<this_v->size<<endl;
	cout<<"now v is :"<<endl;
	for(int i=0;i<this_v->size;i++){
		cout<<this_v->elem[i]<<" "; 
	}
	cout<<"\n vector end!"<<endl;
}

void output_array(T *A, int n){//�ֶ�����size 
	cout<<"now array is :"<<endl;
	for(int i=0;i<n;i++){
		cout<<A[i]<<" "; 
	}
	cout<<"\n Array end!"<<endl;
}

int find(Vector* this_v,int lo ,int hi, T e){
	//ʹ��while��ѭ��
	while(lo<hi-- && this_v->elem[hi]!=e);//�ƶ�������hi 
	return hi;//������excel������Ҳ��� ���ִ�lo=hi�Ժ�  ��-1��һ�� ����hi=lo-1 
}

int insert(Vector* this_v, int r, T const& e){//���ز������ 
	expand(this_v);//�Ƚ������ݼ��
	for(int i=this_v->size ; i>r ; i--){//���ͣ������ʱ�� i=r�Ȼ����������
		this_v->elem[i]=this_v->elem[i-1];//��Ϊ�ʼ���Ǵ�a[size]=a[size-1]��ʼ�� һֱ�� a[r+1]=a[r] ������i=r+1 i=r�Ѿ��������� ����i>r���Խ��� 
	}//a[r]�Ѿ��ճ����� 
	this_v->elem[r]=e;
	this_v->size++;
	return r;
}

int remove(Vector* this_v, int lo,int hi){// ɾ��[lo,hi) ����ɾ����Ԫ�ظ���hi - lo 
	while(hi<this_v->size){//��size���� �Ϳ������������滹ʣ�����ƶ������� 
		this_v->elem[lo++]=this_v->elem[hi++];//�ӱ�ɾ���ĵ�һ����ʼ���� ����ɾ������ĵ�һ��[hi]��ʼ�ƶ� 
	} 
	this_v->size=lo; //���޸�size��Χ���޶����ʣ���Ϊ�ڴ�����ڲ���仯�����Ըķ��ʿ��ƾ�����
	shrink(this_v); 
	return hi-lo;
} 
int remove(Vector* this_v, int r){// ɾ��elem[r] ����elem[r]��ֵ 

	T e=this_v->elem[r];//������Ҫɾ����Ԫ�� 
	remove(this_v,r,r+1);
	//û��shrink�� �����Ǿ������ֲ������û��Ҫ�� //����Ϊshrink�Ѿ���������
	cout<<e<<" is removed. "<<endl; 
	return e;
} 

int deduplicate(Vector *this_v){//����ȥ�������˼���Ԫ�� 
	int i=1;//��1�ſ�ʼ��������Ԫ�ز��в��� 

	int old_size=this_v->size; //�����ʼ��size��С 
	while(i<this_v->size){//sizeҲ��һֱ�ڸ��µģ���֮�����ߵ����ͺ��� 
//		T e=this_v->elem[i];//��¼��ǰ��ȥ�Ƚϵ�Ԫ�� ��һ���÷�����while���� ���򲻻���� 
		if (find(this_v,0,i,this_v->elem[i])<0 ){//bug�ҵ��� �����ҵ�������Ҫʵʱ����  
		///	cout<<"the find result "<<find(this_v,0,i,e)<<endl;
		//		cout<<"now in rank "<<i<<" not find!"<<endl;
			i++;
		}
		else{
	//		output(this_v);
	//		cout<<"now find "<<e<<" in 0~"<<i<<endl;
	//		cout<<"the find result "<<find(this_v,0,i,e)<<endl;
			remove(this_v,i);
		}
	//Ҳ����д�� (find(this_v,0,i,elem[i])<0) ?  {i++; cout<<"not find!"<<endl;} : {remove(this_v,i); };//�����ʽ �����T(<1) �������ظ� ��FΪ���ظ�������˵��ǰ���Ѿ����ˣ� 
		//Ϊ�˷����Ķ�?ǰ��ı��ʽ���������
		//��if������֭���� ܳ 
	}
	return old_size - this_v->size;
}

int disordered( Vector *this_v ){//�ж��Ƿ�Ϊ��������Ϊ0���������0 
	int n=0;//������ 
	for( int i=1; i<this_v->size ;i++){
		if(this_v->elem[i-1]>this_v->elem[i]) n++;// ������쳣��� ������������ 
	} 
	return n;
}

int uniquify( Vector *this_v ){//����ȥ�أ��ж�ɾ���˼��� 
	int old_size=this_v->size;
	int i=0;
	while(i<(this_v->size)-1){//�ѹ��鱾������ԭ���������ǻ�-1 д�������鷳 
		(this_v->elem[i]==this_v->elem[i+1])? remove(this_v,i+1) : i++ ;
	}
	return old_size-this_v->size; 
} 

//����ָ�뷨 :�����Сbug 
//	Vector **v2_a=&v2;//v2�ĵ�ַ��v2_a

/*��覴õ�**A�� 
void construct_vector_copy(T const *A,int lo,int hi, Vector **this_va) {//������һ�������ʼ���Ĺ��캯�� copy����A�����A[lo,hi)������������ 
	cout<<"start copy construction !"<<endl;
	int capacity=2*(hi-lo);//������һ�ֹ涨 �涨������Ϊ2*(hi-lo) 
	//���*��ȡ�βε�ֵ *this_va=this_v
	Vector* this_v =*this_va;
	this_v=new Vector();//Vector* = new vector() ���ȸ�thisvһ��ʵ����vector�ռ� �ɹ��� �ǲ���Ҫ��������ô��Ŀռ�����vector[c]�� 
	this_v->elem = new T[capacity];//��������ռ� 
	//ELEMҲֻ����һ��ָ�� Ҫ����� 
	this_v->capacity=capacity;
//	this_v->size=size; size���Ǹ�ֵ�� ������lo��ֵ�ۼӵ�
	this_v->size=0;//�ʼ��ֵǰsize��0
	int size=0; 
	while(lo<hi){//lo��hi-1��ʱ�������һ�� 
		cout<<"now Alo is "<<A[lo]<<". ";//ͦ������ �ղ�զ�� 
		this_v->elem[this_v->size++]=A[lo++]; //�����Ժ��ȸ�ֵ ��++ ��i++��i�Ȳ��Լӣ����������Լ� ��˴˴��൱�����һ�α�ִ�еĸ�ֵ��hi-1 
		//���Ƶ���elem��[0,hi-lo) 
//		size=size++;
		//lo=lo+1;//��ʾ��ǰ�Ļ���-1 
		cout<<"now v is "<<this_v->elem[(this_v->size-1)]<<". now rank is: "<<(this_v->size-1)<<". now size is: "<<this_v->size<<endl;//size���������Ԫ�ظ��� ������ȴ�1 
	}//ѭ�������ж�hi-lo�� 
	this_v->size=size;
	cout<<"finish !"<<endl;
	return;
}//���������캯���漰new������ָ�� 
*/ 
//���صȺ� �����л�ȽϺò��������������� 


