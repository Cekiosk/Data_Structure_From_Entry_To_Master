#include<iostream>
using namespace std;
#define DEFAULT_CAPACITY 2
#include   <stdlib.h>      
#include   <time.h>   

//我记得cpp比起宏定义常量使用的多 但手写一般宏定义 
/*
struct vector{
}; *///cpp中这种形式与typedef都可以
//还有一个rank表示秩的 我不定义了 手写一般不会有它 
typedef int T;//表示任意数据类型，此处暂时用int 真的要实现的话需要使用模板 

typedef struct{
	int size;//规模 数据区实际填的值 
	int capacity; //数据区的最大空间(动态数组的大小) 
	T *elem;//就是整数数组了 数据区 
}Vector;//定义向量的结构体 那就不考虑的类的结构了 单独写吧 

int main(){
	Vector* construct_vector(Vector *this_v,int size=2,int capacity=DEFAULT_CAPACITY ,int elem_value=0);//普通构造 
	Vector* construct_vector_copy(T const *A,int lo,int hi, Vector *this_v);//复制构造 
	void assigned(Vector* v_assigned, Vector &v );//赋值 
	Vector* expand(Vector* this_v);//扩容   可以在插入前扩容 
	Vector* shrink(Vector* this_v);//缩容  可以在删除后缩容 
	T& get(Vector* this_v, int i);//得到元素 并且返回的是引用可以赋值 
	void swap(T &a, T &b);//交换传进来的两个元素 
	void permute(Vector* this_v);//乱序 
	void output(Vector* this_v);
	void unsort(Vector* this_v,int lo,int hi);//区间乱序 
	int find(Vector* this_v,int lo ,int hi, T e);//返回 在[lo,hi)与e最高相等元素的秩  无即返回lo-1 
	int insert(Vector* this_v, int r, T const& e);//返回插入值的秩 
	int remove(Vector* this_v, int lo,int hi);// 删除[lo,hi) 返回删除的元素个数hi - lo 
	int remove(Vector* this_v, int r);// 删除elem[r] 返回elem[r]的值 
	int deduplicate(Vector *this_v);//无序去重。返回去重消掉了几个元素 
	int disordered(Vector *this_v); //是否有序判定 有序则返回0 
	int uniquify( Vector *this_v );//有序去重，判定删掉了几个 
	int bin_search_B(T *A , int lo, int hi, T e); 
	void bubble_sort_A(T *A,int n);//最简单冒泡排序 
	void output_array(T *A, int n);//输出数组，要自己手动 输入size 
	void bubble_sort_keshe(T r[], int n) ;//课设的bubble sort 
	void merge( T *elem , int lo ,int hi ,int mi);//对一个数组有序两段的二路归并 
	void merge_sort(T *A, int lo , int hi);//二路归并排序 
//***************************函数声明区	


	srand((unsigned int)(time(NULL))); //产生随机数种子 
	
	Vector *v1,*v2;//这样想想没有析构函数挺危险的 
	T A[6]={999,5,6,1,2,6};//拿来被复制的数组 
//****************基础构造法的使用 
//	v2=construct_vector(v1,3,6,9);//初始构造函数 记得在使用结束删掉它 v1 size是3 
//	int size=v2->size; 
//	cout<<"test(return):"<<size<<endl;//这个是return法的反馈
//	cout<<"test(return elme1):"<<v2->elem[1]<<endl;//这个是return法的反馈
//************************************	

//****************二路归并排序的使用
	 
	output_array(A, 6); 
	cout<<"mergesort result: "<<endl; 
	merge_sort(A,0,6);//mi是归后半段的 
	output_array(A, 6); 
		
//******************************************


//
////****************二路归并的使用
//	 
//	output_array(A, 6); 
//	cout<<"merge result: "<<endl; 
//	merge(A,0,3,6);//mi是归后半段的 
//	output_array(A, 6); 
//		
////******************************************

////****************冒泡排序A的使用 
//	output_array(A, 6); 
//	cout<<"bubble sort result: "<<endl; 
//	bubble_sort_A(A,6);
//	bubble_sort_keshe(A,6);
//
//	output_array(A, 6); 	
////******************************************


////****************二分查找B的使用 
//	cout<<"bin search result: "<< bin_search_B(A, 0, 6, 6)<<endl; 
////******************************************
	
	
//****************复制构造法的使用 
	v1=construct_vector_copy(A,0,6,v2);//复制构造函数 v2size是5 
	int size2=v1->size; 
//******************************************

//***************有序去重的应用 
//	v1->capacity=6;//
//	output(v1);
//	cout<<"after uniquify "<<uniquify(v1)<<" element in the vector is remove."<<endl;//失败会返回lo-1 
//	output(v1);
//***********************


////***************判定是否有序的应用 
//	v1->capacity=6;//
//	output(v1);
//	cout<<"disordered ? "<<disordered(v1)<<endl;//失败会返回lo-1 
//	
////***********************


//
////***************乱序去重的应用 
//	v1->capacity=6;//
//	output(v1);
//
//	cout<<"after deduplicate "<<deduplicate(v1)<<" element in the vector is remove."<<endl;//失败会返回lo-1 
//	output(v1);
////***********************
//

////***************删除单个元素的使用 
//	v1->capacity=6;//构造满了的假象 
//	output(v1);
//	int r=3;
//	cout<<"remove rank "<<r<<"in the vector .the remove element is:"<<remove(v1,r)<<endl;//失败会返回lo-1 
//	output(v1);
////***********************


////***************删除区间的使用 
//	v1->capacity=6;//构造满了的假象 
//	output(v1);
//	int lo=1,hi=6;
//	cout<<"remove ["<<lo<<","<<hi<<")in the vector .the number of remove element is:"<<remove(v1,lo,hi)<<endl;//失败会返回lo-1 
//	output(v1);
////***********************


//
////***************插入的使用 
//	v1->capacity=6;//构造满了的假象 
//	output(v1);
//	int e=999,r=3;
//	cout<<"Insert "<<e<<"in the position" <<r<<".the inserted rank is:"<<insert(v1,r,e)<<endl;//失败会返回lo-1 
//	output(v1);
////***********************


//
////***************无序查找的使用 
//	int e=1;
//	cout<<"for find "<<e<<".the rank is:"<<find(v1,3,6,e)<<endl;//失败会返回lo-1 
//	
////***********************


//***************区间置乱的使用 
//	output(v1);
//	unsort(v1,0,4);
//	output(v1);
//	unsort(v1,4,6);
//	output(v1);	

//***********************


//***************置乱的使用 
//	output(v1);
//	permute(v1);
//	output(v1);
//	permute(v1);
//	output(v1);	

//***********************

//****************交换两个元素的值的使用 
//	int n1=1;
//	int n2=4;
//	
//	swap(get(v1,n1),get(v1,n2));
//	cout<<"I get ["<<n1<<"] element: "<< get(v1,n1) <<endl; //返回引用是返回了值的本体 而不是副本 
//	cout<<"I get ["<<n2<<"] element: "<< get(v1,n2) <<endl; //返回引用是返回了值的本体 而不是副本 

//***********************
	
//****************取元素 (相当于[]的实现)
//	int n=4;
//	//T get_elem=get(v1,n);//这里就是一个普通的赋值 
//
//	T &elem=get(v1,n);//以引用初始化引用 
//	elem =9;
//	cout<<"I get ["<<n<<"] element: "<< get(v1,n) <<endl; //返回引用是返回了值的本体 而不是副本 
//******************************************

//************************扩容的使用（每次insert之前都有扩容 ） 
//	v1->capacity=7;//手动更改容量 
//	cout<<"size:"<<size2<<endl;//这个是**a法的反馈 二重指针法依然有瑕疵之后再研究吧 
//	cout<<"capacity:"<<v1->capacity<<endl;
//	expand(v1);
//********************************* 
	 
//************************缩容的使用（每次insert之前都有扩容 ） 
//	v1->capacity=55;//手动更改容量 
//	cout<<"size:"<<size2<<endl;//这个是**a法的反馈 二重指针法依然有瑕疵之后再研究吧 
//	cout<<"capacity:"<<v1->capacity<<endl;
//	shrink(v1);
//********************************* 
	
	 
//*********************赋值的使用 
//	Vector &v=*v1;//引用收到的应该是一个元素即指针指向的元素 
//	assigned(v2,v);//自动扩容的赋值 
//**************************

	//************之前delete如果放在这 就会出问题 为什么呢？-因为之前这里没东西可以delete 
	delete[] v1->elem;
	delete v1; //使用结束记得删除 

//	delete[] v2->elem;
//	delete v2; //使用结束记得删除 

	cout<<"DELETED !"<<endl;
	return 0;
}


//=======二路归并
void merge( T *elem , int lo ,int mi ,int hi){//参数表写错了 
	void output_array(T *A, int n);//输出数组，要自己手动 输入size 
	//计算前后两个数组[lo,mi) [mi,hi)的长度
	int lb=mi-lo; 
	int lc=hi-mi; 
	//先安排：重命名原有数组的[lo,hi)段为 A ； 前半段放进新地址B  ；后半段给新名字 C(覆盖不了的)
	//小技巧：二分法处理一个数列的时候，要是两个分段都从第一个处理到最后一个，那后半段永远不会被覆盖的，就可以用截取法 


	T *A =elem+lo ;//数组本质是一个不会变的地址 是地址赋值吧？ 
	
	T *B =new T[lb];//new新数组也是需要给大小的，但是可以在预编译/甚至执行到这之后依然索要新的空间，是编译语言有这东西的原因 
	//这个时候已经不用想指针嫁接截断了 直接复制值过来
	for(int i=0; i<lb ;B[i]=A[i++]);//复制过程，A已经从lo处截断好了
	
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

	//A,B,C安排好接下来进入二路选择环节
	//记得lc长度的数组最后一个是lc-1，即kc的最大值就是lc-1 
	//停止条件是：当B还有kb<lb 或者 C还有 kc<lc 都要继续 并且要声明三个变量的记录针 ka kb kc 
	for(int ka=0,kb=0,kc=0; (kb<lb||kc<lc);){//for的第二个空作用和while一样，是当为1时候继续 ,虽然第三个空不填 还是需要两个分号 
		//装填B的条件是 (B还有 && (c没了 || B[kb]<=C[kc])) //相等优先小序列 
		if(kb<lb&& ( !(kc<lc) || B[kb]<=C[kc] )){
			A[ka++]=B[kb++];
		}
		//装填C同理 
		
		if(kc<lc&& ( !(kb<lb) || B[kb]>C[kc] )){
		//test  
		//else{//似乎用else效果也是一样的,但写出来更清晰 
			A[ka++]=C[kc++];
		}
	}//for
	output_array(A, 6); 
	delete[] B;//删除临时创建的B 

	return;	
	}
 
//========排序算法 

void merge_sort(T *A, int lo , int hi){//二路归并排序 
	if(hi-lo<2){//其实是 hi-lo==1 递归基 
		return;//返回单元素，即什么也不需要对单元素做 
	}
	else{ 
	int mi = (lo+hi)>>1;
	merge_sort(A,lo,mi);merge_sort(A,mi,hi); //返回排好序的两个子序列
	merge(A,lo,mi,hi);//把这俩有序序列整成一个大有序的
	return;//普通情况结束
	} 
}

void bubble_sort_keshe(T r[], int n) {  //数据结构课设冒泡排序 
	int change=0,move=0,vs=0; 
    int i= n -1;  //初始时,最后位置保持不变  
    while ( i> 0) {   //i一定会变小吗？为什么 
        int pos= 0; //每趟开始时,无记录交换  
        for (int j= 0; j< i; j++,vs++)  
            if (r[j]> r[j+1]) {  
                pos= j; //记录交换的位置   
                swap(r[j],r[j+1]);
                change++;                
            }   
        i= pos; //为下一趟排序作准备  
     }
     
	move=change*3;
	cout<<"冒泡排序结束了！"<<endl;
    cout<<"移动次数:"<<move<<endl;
	cout<<"比较次数:"<<vs<<endl;
}    

void bubble_sort_A(T *A,int n){//排序算法需要同时传入数组长度  ,除非传进来向量从向量里面调用（算法为本的设计没那么麻烦 
	bool sorted=false; //默认为排序不正确，不然进不去; 进去了再置为正确 
	while(!sorted){
		sorted=true;
		for(int i=1; i<n ;i++){//每轮都扫描除去上一轮最大值的全体 
			if (A[i]<A[i-1]){
				swap(A[i],A[i-1]);
				sorted=false;
			}
		}
		n--;//最大值肯定已经摆上合适的值了，这就是冒泡的含义 
	}
} 
 
//============== 

//========查找算法

int bin_search_B(T *A , int lo, int hi, T e){//输入数列与搜素范围，返回对应的秩/-1 
	int mid;
	while((hi-lo)>1){
		mid = (hi+lo)>>1;
//		(A[mid]<e)? hi=mid : lo=mid;//这一行纯粹是弱智式写反了 
//		(A[mid]>e)? hi=mid : lo=mid; //正解 
		(A[mid]>=e)? hi=mid : lo=mid;  //试试把等于的情况放到[lo,mi)来  为什么最后取hi也可以？因为最后这种情况的mid会慢慢逼近到hi-1然后停下，此时的lo是hi-2依然满足条件 
		
	}//因为这是有序向量查找算法 憨批 
	cout<<A[lo]<<endl; 
//	return (e==A[lo])? lo : -1; //正解	
	return (e==A[hi])? hi : -1; //如果等于放到[lo,mi) 就用这个 是可以的 只是说取hi对于整个过程而言不太规范 
} 
//============== 
//首先得构造出实体这一步 我是不是没有做啊 从向量的定义上是一个向量里有一个完整的顺序表 所以向量只需要定义1个 
Vector* construct_vector(Vector *this_v,int size=2,int capacity =DEFAULT_CAPACITY ,int elem_value=0){//用return法返回影响 
	cout<<"start construction !"<<endl;//可是我也没有取指针的值哦 
	this_v=new Vector();//Vector* = new vector() 首先给thisv一个实例的vector空间 成功了 是不需要给容量那么大的数组空间的 
	this_v->capacity=capacity;
	this_v->size=size; 
	this_v->elem = new T[capacity];	//相当于T*=new T[] 首先 this_v并未被初始化 
	for(int i=0;i<size;i++){
		this_v->elem[i]=elem_value;
		cout<<"now v is "<<this_v->elem[i]<<". now size is: "<<this_v->size<<endl;
	}
//	delete[] this_v->elem;//******delete 放在这 就不会出问题 
//	delete this_v; //使用结束记得删除 
	cout<<"finish !"<<endl;//在一个函数内就可以 不在就不行？ 
	return this_v; 
} 	//	这个是传入与直接修改 也可以return指针？ 
Vector* construct_vector_copy(T const *A,int lo,int hi, Vector *this_v) {//利用另一个数组初始化的构造函数 copy的是A数组的A[lo,hi)（到数据区） 
	cout<<"start copy construction !"<<endl;
	int capacity=2*(hi-lo);//怀疑是一种规定 规定新容量为2*(hi-lo) 对的!因为要给拓展空间 

	this_v=new Vector();//Vector* = new vector() 首先给thisv一个实例的vector空间 成功了 是不需要给容量那么大的空间数组vector[c]的 
	this_v->elem = new T[capacity];//给数据组空间 
	//ELEM也只给了一个指针 要区间的 
	this_v->capacity=capacity;
//	this_v->size=size; size不是赋值的 是随着lo赋值累加的
	this_v->size=0;//最开始赋值前size是0
//	int size=0; 
	while(lo<hi){//lo是hi-1的时候是最后一次 
		cout<<"now Alo is "<<A[lo]<<". ";//挺正常啊 刚才咋了 
		this_v->elem[this_v->size++]=A[lo++]; //进来以后先赋值 再++ ，i++是i先不自加，在语句完后自加 因此此处相当于最后一次被执行的赋值是hi-1 
		//复制到了elem的[0,hi-lo) 
//		size=size++;
		//lo=lo+1;//显示当前的话得-1 
		cout<<"now v is "<<this_v->elem[(this_v->size-1)]<<". now rank is: "<<(this_v->size-1)<<". now size is: "<<this_v->size<<endl;//size最后还是已有元素个数 比最大秩大1 
	}//循环次数判断hi-lo次 
//	this_v->size=size;这一步如果上面的发生在本来size上就没用了 
	cout<<"finish !"<<endl;
	return this_v;
}//这两个构造函数涉及new必须用指针 

void assigned(Vector* v_assigned, Vector &v ){//我不搞链式了 而且要改值前面变成*指针 
	cout<<"start assign !"<<endl;
	if(v_assigned){//值存在 就先释放 引用不可以用->符号 
		delete[] v_assigned->elem;//释放原有内容 为什么不直接全删了呢 在这里可以全删 在那边始终是同一个 无必要 
		delete v_assigned; //主要是copy操作对我的而言完全是创造了新向量 某办法了（于我而言是构造函数的一种）
		//如果我的 复制不构造新函数咋写 传入一个指着已有数据的指针进来取值就行 但绝对没这个好用 
	} 
	cout<<"v size:"<<v.size<<endl;
	cout<<"v elme3:"<<v.elem[3]<<endl;
	v_assigned=construct_vector_copy(v.elem,0,v.size,v_assigned) ;//原来是你也得有返回值才行 
	cout<<"END assign copy!"<<endl;//我的赋值函数默认只会出来两倍的c 不太好用 （来扩容 不过好像已经有那个意思了 即我的assign是自动扩容的） 
	return;
	 
}//算了就整个实现 不重载了 

Vector* expand(Vector* this_v){//扩容 
//	int size=this_v->size;
//	int capacity=this_v->capacity;//给变量起别名用引用！
 	int& size = this_v->size; 
	int& capacity = this_v->capacity ; 
	cout<<"initial capacity is:"<<capacity<<endl;
	if(size<capacity) {cout<<"still enough!"<<endl; return this_v;} //容量没超 不然才继续 
	
	cout<<"overflow! start expand !"<<endl;
	if(capacity<DEFAULT_CAPACITY) capacity=DEFAULT_CAPACITY;//注意，需要更新的只是数据区 elme
	T* old_elem = this_v->elem;
	this_v->elem=new T[capacity<<=1];//找一块两倍大的新空间 注意这里的capacity变化对elem不影响 虽然在一个向量内 但是俩属性 
	//扩容以后就够吗？这里应该是传进来前的检查保证的 
	cout<<"now new capacity is:"<<capacity<<endl;
	cout<<"now new capacity is:"<<this_v->capacity<<endl;
	for(int i=0;i<size;i++){ //朴实的依次放入 
		this_v->elem[i]=old_elem[i];//相当于本结构体指向的数据区变了 和整体无关 删除原数据区就好了 
	}
	//我还没有手动的把参数值改了 或者中途全程用也行（但是太烦辽 
//	int size=this_v->size;
//	int capacity=this_v->capacity;
	delete[] old_elem;
	cout<<"EXPAND SUCCESS AND DELETE THE OLD MEMORY !"<<endl;
	cout<<"now new capacity is:"<<this_v->capacity<<". and size is :"<<this_v->size<<endl;
	return this_v;//说不定这个不返回也行因为没有改变原值 我试试 
}


Vector* shrink(Vector* this_v){//缩容  
//	int size=this_v->size;
//	int capacity=this_v->capacity;//给变量起别名用引用！
 	int& size = this_v->size; 
	int& capacity = this_v->capacity ; 
	cout<<"initial capacity is:"<<capacity<<endl;

	if(capacity<DEFAULT_CAPACITY<<1) {cout<<"still reach default!"<<endl; return this_v;} //保证缩容以后不会小于默认容量 

	if(size<<2>capacity) {cout<<"dont need shrink!"<<endl; return this_v;} //size >1/4capacity 都不缩 
	
	cout<<"underflow! start shrink !"<<endl;

	T* old_elem = this_v->elem;// 指针=指针 其实是数据区的嫁接 
	this_v->elem=new T[capacity>>=1];//找一块缩小1/2的新空间 注意这里的capacity变化对elem不影响 虽然在一个向量内 但是俩属性 

	cout<<"now new capacity is:"<<capacity<<endl;
	cout<<"now new capacity is:"<<this_v->capacity<<endl;
	for(int i=0;i<size;i++){ //朴实的依次放入 
		this_v->elem[i]=old_elem[i];//相当于本结构体指向的数据区变了 和整体无关 删除原数据区就好了 
	}
	//我还没有手动的把参数值改了 或者中途全程用也行（但是太烦辽 
//	int size=this_v->size;
//	int capacity=this_v->capacity;
	delete[] old_elem;
	cout<<"SHRINK SUCCESS AND DELETE THE OLD MEMORY !"<<endl;
	cout<<"now new capacity is:"<<this_v->capacity<<". and size is :"<<this_v->size<<endl;
	return this_v;//说不定这个不返回也行因为没有改变原值 我试试 
}

T& get(Vector* this_v, int i){ //返回引用 即返回你传进来的对象本身的别名 即可以作为 左值对其赋值 
	return this_v->elem[i];
}

void swap(T &a, T &b){
	T t=a;
	a=b;
	b=t;
}

void permute(Vector* this_v){
	for(int i=(this_v->size-1);i>0;i--){//elem[0]是不需要进入循环的 已经被换过了 
		swap(get(this_v,i),get(this_v,rand()%i));
	} 
}

void unsort(Vector* this_v,int lo,int hi){//书本是区间截断法 
	cout<<"now unsort elem["<<lo<<","<<hi<<")!"<<endl; 
	T* new_elem= this_v->elem+lo;//从首地址是0 在地址是0+lo的地方插入一个指针 对此指针的操作相当于在原有数组上截出来的新数组 
	//我还得新增一个取代this_v数组的操作？ 
	for(int i=(hi-lo-1);i>0;i--){//现在循环的是新数组 最后一个值是new_v[hi-lo-1] //elem[0]是不需要进入循环的 已经被换过了 
		swap(new_elem[i],new_elem[rand()%i]);//行吧 按照课本的话本处的swap仅仅交换elem值 与this v无关 与this_v的交集在第一个等式 
	} //注意到 unsort因为多出了插入指针操作 访问的东西确实和permute是不一样的 
}


void output(Vector* this_v){
	cout<<" now size is: "<<this_v->size<<endl;
	cout<<"now v is :"<<endl;
	for(int i=0;i<this_v->size;i++){
		cout<<this_v->elem[i]<<" "; 
	}
	cout<<"\n vector end!"<<endl;
}

void output_array(T *A, int n){//手动传入size 
	cout<<"now array is :"<<endl;
	for(int i=0;i<n;i++){
		cout<<A[i]<<" "; 
	}
	cout<<"\n Array end!"<<endl;
}

int find(Vector* this_v,int lo ,int hi, T e){
	//使用while的循环
	while(lo<hi-- && this_v->elem[hi]!=e);//移动的针是hi 
	return hi;//解析在excel无序查找部分 最后抵达lo=hi以后  又-1了一次 所以hi=lo-1 
}

int insert(Vector* this_v, int r, T const& e){//返回插入的秩 
	expand(this_v);//先进行扩容检查
	for(int i=this_v->size ; i>r ; i--){//最后停下来的时候 i=r等会再来看这个
		this_v->elem[i]=this_v->elem[i-1];//因为最开始就是从a[size]=a[size-1]开始的 一直到 a[r+1]=a[r] 即最后的i=r+1 i=r已经进不来了 所以i>r可以进来 
	}//a[r]已经空出来了 
	this_v->elem[r]=e;
	this_v->size++;
	return r;
}

int remove(Vector* this_v, int lo,int hi){// 删除[lo,hi) 返回删除的元素个数hi - lo 
	while(hi<this_v->size){//用size来卡 就可以做到【后面还剩几个移动几个】 
		this_v->elem[lo++]=this_v->elem[hi++];//从被删除的第一个开始覆盖 ；从删除掉后的第一个[hi]开始移动 
	} 
	this_v->size=lo; //用修改size范围来限定访问，因为内存短期内不会变化，所以改访问控制就行了
	shrink(this_v); 
	return hi-lo;
} 
int remove(Vector* this_v, int r){// 删除elem[r] 返回elem[r]的值 

	T e=this_v->elem[r];//保存下要删除的元素 
	remove(this_v,r,r+1);
	//没有shrink诶 可能是觉得这种操作大多没必要吧 //是因为shrink已经在上面了
	cout<<e<<" is removed. "<<endl; 
	return e;
} 

int deduplicate(Vector *this_v){//返回去重消掉了几个元素 
	int i=1;//从1号开始，有两个元素才有查重 

	int old_size=this_v->size; //保存最开始的size大小 
	while(i<this_v->size){//size也是一直在更新的，总之就是走到最后就好了 
//		T e=this_v->elem[i];//记录当前拿去比较的元素 这一步得发生在while里面 否则不会变了 
		if (find(this_v,0,i,this_v->elem[i])<0 ){//bug找到了 被查找的量必须要实时更新  
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
	//也可以写成 (find(this_v,0,i,elem[i])<0) ?  {i++; cout<<"not find!"<<endl;} : {remove(this_v,i); };//这个等式 如果是T(<1) 则是无重复 是F为有重复（或者说，前面已经有了） 
		//为了方便阅读?前面的表达式都会加括号
		//用if方便老汁测试 艹 
	}
	return old_size - this_v->size;
}

int disordered( Vector *this_v ){//判定是否为有序，是则为0，否则大于0 
	int n=0;//计数器 
	for( int i=1; i<this_v->size ;i++){
		if(this_v->elem[i-1]>this_v->elem[i]) n++;// 如果有异常情况 计数器就增加 
	} 
	return n;
}

int uniquify( Vector *this_v ){//有序去重，判定删掉了几个 
	int old_size=this_v->size;
	int i=0;
	while(i<(this_v->size)-1){//难怪书本是在用原型在坐标那换-1 写起来怪麻烦 
		(this_v->elem[i]==this_v->elem[i+1])? remove(this_v,i+1) : i++ ;
	}
	return old_size-this_v->size; 
} 

//二重指针法 :最后还有小bug 
//	Vector **v2_a=&v2;//v2的地址是v2_a

/*有瑕疵的**A法 
void construct_vector_copy(T const *A,int lo,int hi, Vector **this_va) {//利用另一个数组初始化的构造函数 copy的是A数组的A[lo,hi)（到数据区） 
	cout<<"start copy construction !"<<endl;
	int capacity=2*(hi-lo);//怀疑是一种规定 规定新容量为2*(hi-lo) 
	//这个*是取形参的值 *this_va=this_v
	Vector* this_v =*this_va;
	this_v=new Vector();//Vector* = new vector() 首先给thisv一个实例的vector空间 成功了 是不需要给容量那么大的空间数组vector[c]的 
	this_v->elem = new T[capacity];//给数据组空间 
	//ELEM也只给了一个指针 要区间的 
	this_v->capacity=capacity;
//	this_v->size=size; size不是赋值的 是随着lo赋值累加的
	this_v->size=0;//最开始赋值前size是0
	int size=0; 
	while(lo<hi){//lo是hi-1的时候是最后一次 
		cout<<"now Alo is "<<A[lo]<<". ";//挺正常啊 刚才咋了 
		this_v->elem[this_v->size++]=A[lo++]; //进来以后先赋值 再++ ，i++是i先不自加，在语句完后自加 因此此处相当于最后一次被执行的赋值是hi-1 
		//复制到了elem的[0,hi-lo) 
//		size=size++;
		//lo=lo+1;//显示当前的话得-1 
		cout<<"now v is "<<this_v->elem[(this_v->size-1)]<<". now rank is: "<<(this_v->size-1)<<". now size is: "<<this_v->size<<endl;//size最后还是已有元素个数 比最大秩大1 
	}//循环次数判断hi-lo次 
	this_v->size=size;
	cout<<"finish !"<<endl;
	return;
}//这两个构造函数涉及new必须用指针 
*/ 
//重载等号 在类中会比较好不过我在外面试试 


