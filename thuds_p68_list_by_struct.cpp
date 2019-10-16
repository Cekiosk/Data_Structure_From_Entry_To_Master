#include<iostream>

using namespace std;

typedef int T;
//thuds是直接定义了双向链表节点对象  
typedef struct DLNode{//为了方便 thuds也未封装，而是用的结构体 
	T data;
	struct DLNode *next;
	struct DLNode *prior;
	
	//构造函数//相当于把struct当成类用（是为了写默认值加的它）
	DLNode(){};//为了head与trailer 
	DLNode(T e, DLNode *prior_p=NULL ,DLNode *next_p=NULL ){//不指定则单节点默认前后指针都挂起 
		data=e;
		next=next_p;
		prior=prior_p;
		cout<<"the node is consructed, the data is:"<<data<<endl;
		return;
	} 
}DLNode; 

typedef struct List{//为了方便 thuds也未封装，而是用的结构体 
	int size;
	DLNode *header;//指向头结点 
	DLNode *trailer;//指向尾节点 
}List;

//=========函数声明区
void construct_DLNode(struct LNode &this_n,T e, struct LNode *next_p, struct LNode *prior_p );//不指定则单节点默认前后指针都挂起 
List* construct_List();//构架list并返回指向该list的指针 
DLNode* insert_node_prior(DLNode *this_n , T e);//插入节点 这个还必须得在列表里用才能万无一失 
DLNode* insert_list_last (List* this_l ,T e) ;//插入在末节点,返回的还是新节点位置 
DLNode* insert_list_first (List* this_l ,T e);
void traverse_list(List* this_l);
DLNode* find (DLNode *p ,T e ,int n);//是从p往前找n个 
List* copy_construct_list(DLNode *p, int n);//复制构造法 
T& rank_get(List* this_l, int r); //按秩访问，相当于[] 
T remove(List *this_l ,DLNode * p);//后面的p也是前面的指针里节点的位置 ;	//想想这个函数也用引用的话？--无意义，因为副本值会消亡的 不会消亡的才可以这么传 
int deconstruct(List * this_l);//析构函数，返回old size 
int deduplicate(List * this_l);//无序去重 
DLNode* search(DLNode *p, int n, T const & e); //找p的n个真前驱（不包括p） 
void insert_sort(DLNode *p ,int n,List *this_l);//插入排序 
DLNode* select_max(DLNode *p , int n);
void select_sort(DLNode *p, int n, List *this_l);//选择排序 
void merge( DLNode* p, int pn ,List * this_l , DLNode *q, int qn ,List *Lq);//有序二路归并 
void merge_sort(DLNode* p ,int n,List * this_l );//归并排序 
//==================== 	


int main(){

//**************列表构造+插入+遍历输出的实现 
	List *La= construct_List();
	insert_list_last(La,2);
	insert_list_last(La,3); 
	insert_list_first(La,99);
	insert_list_first(La,6);
	insert_list_first(La,3);
	traverse_list(La);
//*************************** 	

//**************复制链表实现 
	DLNode *La_first=La->header->next; 
	int n=La->size;
	List *Lb=copy_construct_list(La_first, n); 
	traverse_list(Lb);
	cout<<"pn:"<<La->size<<endl;
//*************************** 

//*************插入排序实现 
	insert_sort(La->header->next ,La->size,La); 
	traverse_list(La);
	cout<<"pn:"<<La->size<<endl;
	insert_sort(Lb->header->next ,Lb->size,Lb);
	insert_list_last(Lb,9966); 
	traverse_list(Lb);
//*************************** 


//

//*************有序二路归并 
	traverse_list(Lb);
	merge_sort(Lb->header->next ,5,Lb); 
	traverse_list(Lb);
//***************************

////*************选择排序实现 
//	traverse_list(Lb);
////	select_max(Lb->header->next ,1);
////	cout<< Lb->size<<endl;
//	select_sort(Lb->header->next ,Lb->size,Lb); 
//	traverse_list(Lb);
////***************************

////*************有序二路归并 
//
//	cout<<"merge"<<endl; 
//	cout<<"pn:"<<La->size<<endl;
//	merge( La->header->next ,La->size, La , Lb->header->next ,Lb->size,Lb );
//	traverse_list(La); //从下面遍历的代码看遍历会自己执行到尾巴的 
	///// 
//	cout<<"traverse and output the list:";
//	for( DLNode *p = this_l->header->next ; p!=this_l->trailer ; p=p->next){//for循环可以初始化指针，最后一格其实只代表着【执行】，所以也可以写指针的移动 
//	//并且出了for循环在里面声明的东西就消亡了 
//		cout<<" "<<p->data; 
//	}
//	cout<<""<<endl;
////***************************


////*************有序查找实现 
//	search(La->trailer, 3, 99) ; //找p的n个真前驱（不包括p） 
////	traverse_list(La);
////*************************** 

////*************无序去重实现 
//	deduplicate(La);
//	traverse_list(La);
////*************************** 


////*************析构函数实现 
//	cout<<"old size"<<deconstruct(La)<<endl;
////*************************** 

////**************移除元素实现 
//	cout<<remove(La,La_first)<<endl;
//	traverse_list(La);
////*************************** 

////**************按秩访问实现 
//	cout<< rank_get(La, 2)<<endl;
//	rank_get(La, 2)=999;
//	traverse_list(La);
////*************************** 


////**************无序查找链表的实现 
//	int e=6;
//	find (La->trailer ,e , 3); 
//
////*************************** 	

	
//**************插入节点在节点的实现 
//	DLNode A(9);
//	DLNode *pA=&A; 
//	insert_node_next(pA , 3); 
//这个方案不行，因为单节点有风险,那就在列表里插入 
//*************************** 
	 	
////**************列表构造的实现 
//	List *La= construct_List();
////*************************** 
//	delete La;//这个删除应该是不够 
	deconstruct(La);
//	cout<<"deleted!"<<endl; //之后写析构再写删除 
	return 0;
} 

//===================排序算法

//insert_sort

//======================= 

//传入声明以后结构体的引用/指针好了 
//普通的双链表节点构造 
void construct_DLNode(DLNode &this_n,T e, DLNode *next_p=NULL, DLNode *prior_p=NULL ){//不指定则单节点默认前后指针都挂起 
	this_n.data=e;
	this_n.next=next_p;
	this_n.prior=prior_p;
	cout<<"the node is consructed, the data is:"<<this_n.data<<endl;
	return;
} //我把相同功能的东西移动到struct内部去了 

//thuds是做法是声明一个新的list结构体，里面装着头尾隐藏节点的指针
//但是实际上似乎使用DLNode* 就可以指向list的头部 (但是没有size这些信息，也无法记录尾巴)

List* construct_List(){
	List *this_l = new List;
	this_l->size=0;
//	this_l->header=new DLNode(0,NULL,this_l->trailer);//作用大概和手动做下面的链接一样 
	this_l->header=new DLNode; 
	this_l->trailer=new DLNode;//本体没有值，我就不用构造函数弄了 
	//链接前驱后继 
	this_l->header->prior=NULL;//header的前面是NULL 
	this_l->header->next=this_l->trailer; //header后面是trailer
	this_l->trailer->prior=this_l->header;//trailor的前面是header
	this_l->trailer->next=NULL;//trailor的后面是NULL
	
	cout<<"list has been constructed!"<<endl;
	return this_l;
} 

DLNode * insert_node_prior(DLNode *this_n , T e){//p是指针，一般表示移动和指示的时候用，做定位/被操作对象还是this
	DLNode *x= new DLNode(e,this_n->prior,this_n);//在这里就初始化好新节点的前后 
	cout<<"the new data: "<<x->data<<endl; 
	this_n->prior->next=x;//贸然的用，这里没有前驱 好危险啊 
	this_n->prior=x;
	cout<<"insert in prior"<<x->data<<endl; 
	return x;//返回新节点位置 
}

DLNode * insert_node_next(DLNode *this_n , T e){//p是指针，一般表示移动和指示的时候用，做定位/被操作对象还是this
	DLNode *x= new DLNode(e,this_n,this_n->next);//在这里就初始化好新节点的前后 
	cout<<"the new data: "<<x->data<<endl; 
	this_n->next->prior=x;//贸然的用，这里没有前驱 好危险啊 
	this_n->next=x;
	cout<<"insert in next:"<<x->data<<endl; 
	return x;//返回新节点位置 
}


//那写一个在列表里用的
DLNode* insert_list_last (List* this_l ,T e) {//插入在末节点,返回的还是新节点位置   //因为我写了插入到之前的，所以就写这个 
	this_l->size++;
	return insert_node_prior(this_l->trailer,e);//插在尾哨兵的前面 
}

//那写一个在列表里用的
DLNode* insert_list_first (List* this_l ,T e) {//插入在末节点,返回的还是新节点位置   //因为我写了插入到之前的，所以就写这个 
	this_l->size++;
	return insert_node_next(this_l->header,e);//插在尾哨兵的前面 
}

void traverse_list(List* this_l){//其实也是遍历，当成输出用 
	cout<<"traverse and output the list:";
	for( DLNode *p = this_l->header->next ; p!=this_l->trailer ; p=p->next){//for循环可以初始化指针，最后一格其实只代表着【执行】，所以也可以写指针的移动 
	//并且出了for循环在里面声明的东西就消亡了 
		cout<<" "<<p->data; 
	}
	cout<<""<<endl;
}

DLNode* find (DLNode *p ,T e ,int n){//从哪开始找，找到前面第几个（不包括传进来这个） 
	while(n--){//循环n次的写法 ?是吗 这个写法上来就是2 
		cout<<n<<endl;
//		cout<< (p=p->prior)->data <<",";
		if(e == (p=p->prior)->data ){
			cout<<"get!"<<p->data<<endl;
			return p;//命中则返回当前位置 
		} 
	}//WHILE
	cout<<"NONE"<<endl;
	return NULL;//不然返回null 不是 我这样一开始肯定只能找一次啊
}

List* copy_construct_list(DLNode *p, int n){
	List *L =construct_List();
	while(n--){
		insert_list_last(L,p->data);//包括当前p的后n个 
		p=p->next;
	}
	return L;
} 

T& rank_get(List* this_l, int r){
	DLNode *p= this_l ->header->next;//先把p定位到第一个first 
	for(int i=0; i<r ; i++){//已经定位到[0]了接下来的秩就完全吻合 for循环经历了第一次初始化之后是要判定以后才知道是否进入的 
		p=p->next;
	}
	return p->data;//返回正常值即可 引用加在函数前面的地方 
}

T remove(List *this_l ,DLNode * p){//后面的p也是前面的指针里节点的位置 
	T e=p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	delete p;
	this_l->size--;
	return e;
}

int deconstruct(List * this_l){
	int old_size=this_l->size;//保存原size 
	while(this_l->size>0){ //这里不用size--，在remove里减掉了  >0要不要都行 
		cout<<"delete: "<<remove(this_l,this_l->header->next)<<endl;//永远删除现在的首节点 
	}
	cout<<"delete header and trailer..."<<endl;
	delete this_l->header; delete this_l->trailer;delete this_l;//size怎么办？如果是我自己，应该还要加上一个删掉this_l,课本把这一步交给cpp析构器了 
	cout<<"deleted!"<<endl; 
	return old_size;
	
}

int deduplicate(List * this_l){
	if(this_l->size < 2) return 0; //一个元素不存在重复
	//至少有两个元素；
	int old_size=this_l->size;
	DLNode *p=this_l->header; 
//	DLNode *p=this_l->header->next; 
	int r=0; 
//	int r=1;//如果上面没next这里就是0 
	while(this_l->trailer!=(p=p->next)){ //p会从第二个也就是[1]开始 
	//	int i;//连续声明两次会报错但是放在循环里就可以？ 
		DLNode *q=find(p,p->data,r);//r如何初始化 ，最开始是1肯定是一个,书本是0因为书本从[0]开始的，多了一次find(0)的无用比较等会可以做个试验
		q? remove(this_l,q) : r++ ;//前者既不影响p的指向，也无法使去重序列数量加一 
	}
	return old_size-this_l->size; 
}

DLNode* search(DLNode *p, int n, T const & e){//找p的n个真前驱（不包括p） 
	while(0<=n--){//越界了会停下 这里的等号含义是 n--就算是进来就是0里面也会再走一次 走n+1次 即就算整个遍历完所有也没找到，也会再移动一次来到最前面 
		p=p->prior;//开始前先走一步就是真前驱的体现 
		if(p->data <= e ) {cout<<"i get a "<<p->data<<endl; break ; }// =:命中 ； p<e:找不到了抵达了一个它的next会符合e要求的位置 
	} 
	return p;
}

void insert_sort(DLNode *p ,int n,List *this_l){
	int size=this_l->size;
	//不需要先把p运送到尾巴去，因为p从0起步，每一次增长就是前面的有序区间增长  
	for(int r=0; r<n ;r++){ //r是划分已经有序区间的边界 相当于r的增长与p的移动对应 每个p都在被逐渐插入的 
		//第一趟r=0,search会直接返回
		DLNode* p_ins = search(p,r,p->data); //最适合插入的点 //联系上面的 从后命中即停止 相同元素永远是后面插入的在后面 稳定
		//按照search定义是插在返回位置的后面 因为search发现的时候已经溢出了/没发现会多移动一下 
		insert_node_next(p_ins, p->data);//相当于前面的序列从空序列开始 一个个插入值到合适的位置
		 
		p=p->next;//移动节点在这里 和r的增长同步进行 
		remove(this_l,p->prior);	//p在被成功插入以后是一定要删除的	主要insert_node不+size 得debug一下 
	} 
	this_l->size=size;
} 

DLNode* select_max(DLNode *p , int n){//打擂台式找最大值 选择排序一个位置就得打这样一趟擂台 
	DLNode * max = p ;//得找一根针来存最大节点
//	for(DLNode* cur = p ;n>1 ; n--,cur=cur->next){ //还得找一根针来当临时移动的 别动p,这里初始化只能有一个？ 并且因为提前移动 最后只需要确定比较n-1个元素 n>1
	for(DLNode* cur = p ;n>1 ; n--){ //↑cur放在这 cur是需要在开始前就执行一次的 执行不到 相当于少执行一次 for 
		//比较max和cur 如果 cur 更大 cur替换 如果相等呢？cur是在后面的 它还是替换 后面的值有位子加持理论上更大
		cout<<"now max:"<<max->data<<endl;
		cout<<"now cur:"<<cur->data<<endl;   
		if( (cur=cur->next)->data >= max->data) max=cur; //[e]指针的移动需要	cur=cur->next 光有箭头不行 
		cout<<"bigger one"<<max->data<<endl; 
	} //[C]for循环里的每个分号只能放一条声明语句 如果声明符（比如int）概括不完 就不行 
	cout<<"find max:"<<max->data<<endl; 
	return max;
	
}

void select_sort(DLNode *p, int n, List *this_l){
	//这个需要先定下trailer找到最大值放在最后 更后面的最大值要被先放 就是当做max先选出来 上面是对的 
	DLNode* head=p->prior;//结构体指针不能多个声明 
	DLNode* trailer=p;//排序别动p宗旨 //链表先把首节点的前一个节点位置存下来是规范，把它挂起来传回去的时候再next一定是标准的首节点 
	for(int i=0;i<n;i++) trailer=trailer->next ;//移动尾巴的操作 从[0] 1~n移动到了[n]的地方
	//错误(n-->1)而不是n--摆在最后的话 一样是循环n-1次 但是 这种每次在循环体里的是(n-1)~1 
	while(n>1){//只需要放置n-1个最大值 最后一个一定是对的 
	 //	n--; //这种执行里是(n-1)~1遗漏了一个值 
	//	DLNode *max =select_max(p, n); // 错的 用这个+n--会变出6个值 不太懂 算了 
		DLNode *max =select_max(head->next , n); // 传入的一直是首节点 需要筛选比较的值最开始是n 每次少一个一直到2 
		//我的错误方法在这里 不仅一开始就少比较了一个 ，最后传入1的时候 因为移动指针错乱了 
		//把得到的最大节点插入 后 删除原来的节点 因为max每次都被新赋值不用特地移开也行 
		insert_node_prior(trailer,max->data);
		remove(this_l,max);
		trailer=trailer->prior; //无序区间的尾巴哨兵也要前移 
		n--;//这种 是在最后才变成n-1的 在执行中是 n ~ 2 
	}
	return;
}
void merge( DLNode* p, int pn ,List * this_l , DLNode *q, int qn ,List *Lq){//自La起的p和pn个 与自Lb起的q和qn个 是不一样的 用结构体还得加个针点点点 
//难怪我就感觉remove和inssert明明对应不一样的 this_v
	//记得保存哨兵首节点挂起来：
	traverse_list(this_l); 
	traverse_list(Lq); 
	//====test
	DLNode* head = p->prior; 
	while(qn>0){//后未完
		cout<<"pn:"<<pn <<"qn:"<< qn <<endl;
		cout<<"p:"<<p->data <<"q:"<< q->data<<endl;
		if(pn > 0 && p->data <= q->data){ //前未完且前面比较小 
			if((p=p->next)==q) break;
			else {	cout<<"now put p:"<<p->prior->data<<endl  ; pn--;}
		}
		else{
			T move_data=remove(Lq,(q=q->next)->prior);
			cout<<"now put q:"<<move_data<<endl  ; 
		//	pn--;////??/这是啥 
			insert_node_prior(p,move_data);
			qn--;
		} 
	}
	p=head->next;//p是修正后的首节点 
	return ;
}

void merge_sort(DLNode* p ,int n,List * this_l ){
	cout<<n<<" ←n "<<p->data<<endl; 
	if(n<2) {	cout<<n<<" get bottom :"<<p->data<<endl; return;}//递归基 
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
