#include<iostream>

using namespace std;

typedef int T;
//thuds��ֱ�Ӷ�����˫������ڵ����  
typedef struct DLNode{//Ϊ�˷��� thudsҲδ��װ�������õĽṹ�� 
	T data;
	struct DLNode *next;
	struct DLNode *prior;
	
	//���캯��//�൱�ڰ�struct�������ã���Ϊ��дĬ��ֵ�ӵ�����
	DLNode(){};//Ϊ��head��trailer 
	DLNode(T e, DLNode *prior_p=NULL ,DLNode *next_p=NULL ){//��ָ���򵥽ڵ�Ĭ��ǰ��ָ�붼���� 
		data=e;
		next=next_p;
		prior=prior_p;
		cout<<"the node is consructed, the data is:"<<data<<endl;
		return;
	} 
}DLNode; 

typedef struct List{//Ϊ�˷��� thudsҲδ��װ�������õĽṹ�� 
	int size;
	DLNode *header;//ָ��ͷ��� 
	DLNode *trailer;//ָ��β�ڵ� 
}List;

//=========����������
void construct_DLNode(struct LNode &this_n,T e, struct LNode *next_p, struct LNode *prior_p );//��ָ���򵥽ڵ�Ĭ��ǰ��ָ�붼���� 
List* construct_List();//����list������ָ���list��ָ�� 
DLNode* insert_node_prior(DLNode *this_n , T e);//����ڵ� �������������б����ò�������һʧ 
DLNode* insert_list_last (List* this_l ,T e) ;//������ĩ�ڵ�,���صĻ����½ڵ�λ�� 
DLNode* insert_list_first (List* this_l ,T e);
void traverse_list(List* this_l);
DLNode* find (DLNode *p ,T e ,int n);//�Ǵ�p��ǰ��n�� 
List* copy_construct_list(DLNode *p, int n);//���ƹ��취 
T& rank_get(List* this_l, int r); //���ȷ��ʣ��൱��[] 
T remove(List *this_l ,DLNode * p);//�����pҲ��ǰ���ָ����ڵ��λ�� ;	//�����������Ҳ�����õĻ���--�����壬��Ϊ����ֵ�������� ���������Ĳſ�����ô�� 
int deconstruct(List * this_l);//��������������old size 
int deduplicate(List * this_l);//����ȥ�� 
DLNode* search(DLNode *p, int n, T const & e); //��p��n����ǰ����������p�� 
void insert_sort(DLNode *p ,int n,List *this_l);//�������� 
DLNode* select_max(DLNode *p , int n);
void select_sort(DLNode *p, int n, List *this_l);//ѡ������ 
void merge( DLNode* p, int pn ,List * this_l , DLNode *q, int qn ,List *Lq);//�����·�鲢 
void merge_sort(DLNode* p ,int n,List * this_l );//�鲢���� 
//==================== 	


int main(){

//**************�б���+����+���������ʵ�� 
	List *La= construct_List();
	insert_list_last(La,2);
	insert_list_last(La,3); 
	insert_list_first(La,99);
	insert_list_first(La,6);
	insert_list_first(La,3);
	traverse_list(La);
//*************************** 	

//**************��������ʵ�� 
	DLNode *La_first=La->header->next; 
	int n=La->size;
	List *Lb=copy_construct_list(La_first, n); 
	traverse_list(Lb);
	cout<<"pn:"<<La->size<<endl;
//*************************** 

//*************��������ʵ�� 
	insert_sort(La->header->next ,La->size,La); 
	traverse_list(La);
	cout<<"pn:"<<La->size<<endl;
	insert_sort(Lb->header->next ,Lb->size,Lb);
	insert_list_last(Lb,9966); 
	traverse_list(Lb);
//*************************** 


//

//*************�����·�鲢 
	traverse_list(Lb);
	merge_sort(Lb->header->next ,5,Lb); 
	traverse_list(Lb);
//***************************

////*************ѡ������ʵ�� 
//	traverse_list(Lb);
////	select_max(Lb->header->next ,1);
////	cout<< Lb->size<<endl;
//	select_sort(Lb->header->next ,Lb->size,Lb); 
//	traverse_list(Lb);
////***************************

////*************�����·�鲢 
//
//	cout<<"merge"<<endl; 
//	cout<<"pn:"<<La->size<<endl;
//	merge( La->header->next ,La->size, La , Lb->header->next ,Lb->size,Lb );
//	traverse_list(La); //����������Ĵ��뿴�������Լ�ִ�е�β�͵� 
	///// 
//	cout<<"traverse and output the list:";
//	for( DLNode *p = this_l->header->next ; p!=this_l->trailer ; p=p->next){//forѭ�����Գ�ʼ��ָ�룬���һ����ʵֻ�����š�ִ�С�������Ҳ����дָ����ƶ� 
//	//���ҳ���forѭ�������������Ķ����������� 
//		cout<<" "<<p->data; 
//	}
//	cout<<""<<endl;
////***************************


////*************�������ʵ�� 
//	search(La->trailer, 3, 99) ; //��p��n����ǰ����������p�� 
////	traverse_list(La);
////*************************** 

////*************����ȥ��ʵ�� 
//	deduplicate(La);
//	traverse_list(La);
////*************************** 


////*************��������ʵ�� 
//	cout<<"old size"<<deconstruct(La)<<endl;
////*************************** 

////**************�Ƴ�Ԫ��ʵ�� 
//	cout<<remove(La,La_first)<<endl;
//	traverse_list(La);
////*************************** 

////**************���ȷ���ʵ�� 
//	cout<< rank_get(La, 2)<<endl;
//	rank_get(La, 2)=999;
//	traverse_list(La);
////*************************** 


////**************������������ʵ�� 
//	int e=6;
//	find (La->trailer ,e , 3); 
//
////*************************** 	

	
//**************����ڵ��ڽڵ��ʵ�� 
//	DLNode A(9);
//	DLNode *pA=&A; 
//	insert_node_next(pA , 3); 
//����������У���Ϊ���ڵ��з���,�Ǿ����б������ 
//*************************** 
	 	
////**************�б����ʵ�� 
//	List *La= construct_List();
////*************************** 
//	delete La;//���ɾ��Ӧ���ǲ��� 
	deconstruct(La);
//	cout<<"deleted!"<<endl; //֮��д������дɾ�� 
	return 0;
} 

//===================�����㷨

//insert_sort

//======================= 

//���������Ժ�ṹ�������/ָ����� 
//��ͨ��˫����ڵ㹹�� 
void construct_DLNode(DLNode &this_n,T e, DLNode *next_p=NULL, DLNode *prior_p=NULL ){//��ָ���򵥽ڵ�Ĭ��ǰ��ָ�붼���� 
	this_n.data=e;
	this_n.next=next_p;
	this_n.prior=prior_p;
	cout<<"the node is consructed, the data is:"<<this_n.data<<endl;
	return;
} //�Ұ���ͬ���ܵĶ����ƶ���struct�ڲ�ȥ�� 

//thuds������������һ���µ�list�ṹ�壬����װ��ͷβ���ؽڵ��ָ��
//����ʵ�����ƺ�ʹ��DLNode* �Ϳ���ָ��list��ͷ�� (����û��size��Щ��Ϣ��Ҳ�޷���¼β��)

List* construct_List(){
	List *this_l = new List;
	this_l->size=0;
//	this_l->header=new DLNode(0,NULL,this_l->trailer);//���ô�ź��ֶ������������һ�� 
	this_l->header=new DLNode; 
	this_l->trailer=new DLNode;//����û��ֵ���ҾͲ��ù��캯��Ū�� 
	//����ǰ����� 
	this_l->header->prior=NULL;//header��ǰ����NULL 
	this_l->header->next=this_l->trailer; //header������trailer
	this_l->trailer->prior=this_l->header;//trailor��ǰ����header
	this_l->trailer->next=NULL;//trailor�ĺ�����NULL
	
	cout<<"list has been constructed!"<<endl;
	return this_l;
} 

DLNode * insert_node_prior(DLNode *this_n , T e){//p��ָ�룬һ���ʾ�ƶ���ָʾ��ʱ���ã�����λ/������������this
	DLNode *x= new DLNode(e,this_n->prior,this_n);//������ͳ�ʼ�����½ڵ��ǰ�� 
	cout<<"the new data: "<<x->data<<endl; 
	this_n->prior->next=x;//óȻ���ã�����û��ǰ�� ��Σ�հ� 
	this_n->prior=x;
	cout<<"insert in prior"<<x->data<<endl; 
	return x;//�����½ڵ�λ�� 
}

DLNode * insert_node_next(DLNode *this_n , T e){//p��ָ�룬һ���ʾ�ƶ���ָʾ��ʱ���ã�����λ/������������this
	DLNode *x= new DLNode(e,this_n,this_n->next);//������ͳ�ʼ�����½ڵ��ǰ�� 
	cout<<"the new data: "<<x->data<<endl; 
	this_n->next->prior=x;//óȻ���ã�����û��ǰ�� ��Σ�հ� 
	this_n->next=x;
	cout<<"insert in next:"<<x->data<<endl; 
	return x;//�����½ڵ�λ�� 
}


//��дһ�����б����õ�
DLNode* insert_list_last (List* this_l ,T e) {//������ĩ�ڵ�,���صĻ����½ڵ�λ��   //��Ϊ��д�˲��뵽֮ǰ�ģ����Ծ�д��� 
	this_l->size++;
	return insert_node_prior(this_l->trailer,e);//����β�ڱ���ǰ�� 
}

//��дһ�����б����õ�
DLNode* insert_list_first (List* this_l ,T e) {//������ĩ�ڵ�,���صĻ����½ڵ�λ��   //��Ϊ��д�˲��뵽֮ǰ�ģ����Ծ�д��� 
	this_l->size++;
	return insert_node_next(this_l->header,e);//����β�ڱ���ǰ�� 
}

void traverse_list(List* this_l){//��ʵҲ�Ǳ�������������� 
	cout<<"traverse and output the list:";
	for( DLNode *p = this_l->header->next ; p!=this_l->trailer ; p=p->next){//forѭ�����Գ�ʼ��ָ�룬���һ����ʵֻ�����š�ִ�С�������Ҳ����дָ����ƶ� 
	//���ҳ���forѭ�������������Ķ����������� 
		cout<<" "<<p->data; 
	}
	cout<<""<<endl;
}

DLNode* find (DLNode *p ,T e ,int n){//���Ŀ�ʼ�ң��ҵ�ǰ��ڼ���������������������� 
	while(n--){//ѭ��n�ε�д�� ?���� ���д����������2 
		cout<<n<<endl;
//		cout<< (p=p->prior)->data <<",";
		if(e == (p=p->prior)->data ){
			cout<<"get!"<<p->data<<endl;
			return p;//�����򷵻ص�ǰλ�� 
		} 
	}//WHILE
	cout<<"NONE"<<endl;
	return NULL;//��Ȼ����null ���� ������һ��ʼ�϶�ֻ����һ�ΰ�
}

List* copy_construct_list(DLNode *p, int n){
	List *L =construct_List();
	while(n--){
		insert_list_last(L,p->data);//������ǰp�ĺ�n�� 
		p=p->next;
	}
	return L;
} 

T& rank_get(List* this_l, int r){
	DLNode *p= this_l ->header->next;//�Ȱ�p��λ����һ��first 
	for(int i=0; i<r ; i++){//�Ѿ���λ��[0]�˽��������Ⱦ���ȫ�Ǻ� forѭ�������˵�һ�γ�ʼ��֮����Ҫ�ж��Ժ��֪���Ƿ����� 
		p=p->next;
	}
	return p->data;//��������ֵ���� ���ü��ں���ǰ��ĵط� 
}

T remove(List *this_l ,DLNode * p){//�����pҲ��ǰ���ָ����ڵ��λ�� 
	T e=p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	delete p;
	this_l->size--;
	return e;
}

int deconstruct(List * this_l){
	int old_size=this_l->size;//����ԭsize 
	while(this_l->size>0){ //���ﲻ��size--����remove�������  >0Ҫ��Ҫ���� 
		cout<<"delete: "<<remove(this_l,this_l->header->next)<<endl;//��Զɾ�����ڵ��׽ڵ� 
	}
	cout<<"delete header and trailer..."<<endl;
	delete this_l->header; delete this_l->trailer;delete this_l;//size��ô�죿��������Լ���Ӧ�û�Ҫ����һ��ɾ��this_l,�α�����һ������cpp�������� 
	cout<<"deleted!"<<endl; 
	return old_size;
	
}

int deduplicate(List * this_l){
	if(this_l->size < 2) return 0; //һ��Ԫ�ز������ظ�
	//����������Ԫ�أ�
	int old_size=this_l->size;
	DLNode *p=this_l->header; 
//	DLNode *p=this_l->header->next; 
	int r=0; 
//	int r=1;//�������ûnext�������0 
	while(this_l->trailer!=(p=p->next)){ //p��ӵڶ���Ҳ����[1]��ʼ 
	//	int i;//�����������λᱨ���Ƿ���ѭ����Ϳ��ԣ� 
		DLNode *q=find(p,p->data,r);//r��γ�ʼ�� ���ʼ��1�϶���һ��,�鱾��0��Ϊ�鱾��[0]��ʼ�ģ�����һ��find(0)�����ñȽϵȻ������������
		q? remove(this_l,q) : r++ ;//ǰ�߼Ȳ�Ӱ��p��ָ��Ҳ�޷�ʹȥ������������һ 
	}
	return old_size-this_l->size; 
}

DLNode* search(DLNode *p, int n, T const & e){//��p��n����ǰ����������p�� 
	while(0<=n--){//Խ���˻�ͣ�� ����ĵȺź����� n--�����ǽ�������0����Ҳ������һ�� ��n+1�� ��������������������Ҳû�ҵ���Ҳ�����ƶ�һ��������ǰ�� 
		p=p->prior;//��ʼǰ����һ��������ǰ�������� 
		if(p->data <= e ) {cout<<"i get a "<<p->data<<endl; break ; }// =:���� �� p<e:�Ҳ����˵ִ���һ������next�����eҪ���λ�� 
	} 
	return p;
}

void insert_sort(DLNode *p ,int n,List *this_l){
	int size=this_l->size;
	//����Ҫ�Ȱ�p���͵�β��ȥ����Ϊp��0�𲽣�ÿһ����������ǰ���������������  
	for(int r=0; r<n ;r++){ //r�ǻ����Ѿ���������ı߽� �൱��r��������p���ƶ���Ӧ ÿ��p���ڱ��𽥲���� 
		//��һ��r=0,search��ֱ�ӷ���
		DLNode* p_ins = search(p,r,p->data); //���ʺϲ���ĵ� //��ϵ����� �Ӻ����м�ֹͣ ��ͬԪ����Զ�Ǻ��������ں��� �ȶ�
		//����search�����ǲ��ڷ���λ�õĺ��� ��Ϊsearch���ֵ�ʱ���Ѿ������/û���ֻ���ƶ�һ�� 
		insert_node_next(p_ins, p->data);//�൱��ǰ������дӿ����п�ʼ һ��������ֵ�����ʵ�λ��
		 
		p=p->next;//�ƶ��ڵ������� ��r������ͬ������ 
		remove(this_l,p->prior);	//p�ڱ��ɹ������Ժ���һ��Ҫɾ����	��Ҫinsert_node��+size ��debugһ�� 
	} 
	this_l->size=size;
} 

DLNode* select_max(DLNode *p , int n){//����̨ʽ�����ֵ ѡ������һ��λ�þ͵ô�����һ����̨ 
	DLNode * max = p ;//����һ�����������ڵ�
//	for(DLNode* cur = p ;n>1 ; n--,cur=cur->next){ //������һ����������ʱ�ƶ��� ��p,�����ʼ��ֻ����һ���� ������Ϊ��ǰ�ƶ� ���ֻ��Ҫȷ���Ƚ�n-1��Ԫ�� n>1
	for(DLNode* cur = p ;n>1 ; n--){ //��cur������ cur����Ҫ�ڿ�ʼǰ��ִ��һ�ε� ִ�в��� �൱����ִ��һ�� for 
		//�Ƚ�max��cur ��� cur ���� cur�滻 �������أ�cur���ں���� �������滻 �����ֵ��λ�Ӽӳ������ϸ���
		cout<<"now max:"<<max->data<<endl;
		cout<<"now cur:"<<cur->data<<endl;   
		if( (cur=cur->next)->data >= max->data) max=cur; //[e]ָ����ƶ���Ҫ	cur=cur->next ���м�ͷ���� 
		cout<<"bigger one"<<max->data<<endl; 
	} //[C]forѭ�����ÿ���ֺ�ֻ�ܷ�һ��������� ���������������int���������� �Ͳ��� 
	cout<<"find max:"<<max->data<<endl; 
	return max;
	
}

void select_sort(DLNode *p, int n, List *this_l){
	//�����Ҫ�ȶ���trailer�ҵ����ֵ������� ����������ֵҪ���ȷ� ���ǵ���max��ѡ���� �����ǶԵ� 
	DLNode* head=p->prior;//�ṹ��ָ�벻�ܶ������ 
	DLNode* trailer=p;//�����p��ּ //�����Ȱ��׽ڵ��ǰһ���ڵ�λ�ô������ǹ淶����������������ȥ��ʱ����nextһ���Ǳ�׼���׽ڵ� 
	for(int i=0;i<n;i++) trailer=trailer->next ;//�ƶ�β�͵Ĳ��� ��[0] 1~n�ƶ�����[n]�ĵط�
	//����(n-->1)������n--�������Ļ� һ����ѭ��n-1�� ���� ����ÿ����ѭ���������(n-1)~1 
	while(n>1){//ֻ��Ҫ����n-1�����ֵ ���һ��һ���ǶԵ� 
	 //	n--; //����ִ������(n-1)~1��©��һ��ֵ 
	//	DLNode *max =select_max(p, n); // ��� �����+n--����6��ֵ ��̫�� ���� 
		DLNode *max =select_max(head->next , n); // �����һֱ���׽ڵ� ��Ҫɸѡ�Ƚϵ�ֵ�ʼ��n ÿ����һ��һֱ��2 
		//�ҵĴ��󷽷������� ����һ��ʼ���ٱȽ���һ�� �������1��ʱ�� ��Ϊ�ƶ�ָ������� 
		//�ѵõ������ڵ���� �� ɾ��ԭ���Ľڵ� ��Ϊmaxÿ�ζ����¸�ֵ�����ص��ƿ�Ҳ�� 
		insert_node_prior(trailer,max->data);
		remove(this_l,max);
		trailer=trailer->prior; //���������β���ڱ�ҲҪǰ�� 
		n--;//���� �������ű��n-1�� ��ִ������ n ~ 2 
	}
	return;
}
void merge( DLNode* p, int pn ,List * this_l , DLNode *q, int qn ,List *Lq){//��La���p��pn�� ����Lb���q��qn�� �ǲ�һ���� �ýṹ�廹�üӸ������ 
//�ѹ��Ҿ͸о�remove��inssert������Ӧ��һ���� this_v
	//�ǵñ����ڱ��׽ڵ��������
	traverse_list(this_l); 
	traverse_list(Lq); 
	//====test
	DLNode* head = p->prior; 
	while(qn>0){//��δ��
		cout<<"pn:"<<pn <<"qn:"<< qn <<endl;
		cout<<"p:"<<p->data <<"q:"<< q->data<<endl;
		if(pn > 0 && p->data <= q->data){ //ǰδ����ǰ��Ƚ�С 
			if((p=p->next)==q) break;
			else {	cout<<"now put p:"<<p->prior->data<<endl  ; pn--;}
		}
		else{
			T move_data=remove(Lq,(q=q->next)->prior);
			cout<<"now put q:"<<move_data<<endl  ; 
		//	pn--;////??/����ɶ 
			insert_node_prior(p,move_data);
			qn--;
		} 
	}
	p=head->next;//p����������׽ڵ� 
	return ;
}

void merge_sort(DLNode* p ,int n,List * this_l ){
	cout<<n<<" ��n "<<p->data<<endl; 
	if(n<2) {	cout<<n<<" get bottom :"<<p->data<<endl; return;}//�ݹ�� 
	int mid=n>>1;
	DLNode* q=p;
	for(int i=0 ;i<mid ;i++) q=q->next;
	cout<<"cut1 start"<<endl;
	merge_sort( p ,mid, this_l );
	merge_sort( q ,n-mid, this_l );
	cout<<"cut2 start"<<endl;
	merge( p, mid ,this_l , q, n-mid ,this_l);
	return;
}
