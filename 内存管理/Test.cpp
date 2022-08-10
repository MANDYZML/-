#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//C++内存管理方式

//void Test()
//{
//	int* p1 = (int*)malloc(sizeof(int));
//	free(p1);
//	// 1.malloc/calloc/realloc的区别是什么？
//	int* p2 = (int*)calloc(4, sizeof(int));
//	int* p3 = (int*)realloc(p2, sizeof(int) * 10);
//	// 这里需要free(p2)吗？
//	free(p3);
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//new delete 操作符

//void Test()
//{
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p2 = new int;
//	//申请5个int的数组
//	int* p3 = new int[5];//开多个 开5个int
//	//申请1个int对象，初始化为5
//	int* p4 = new int(5);
//
//	//C++11支持new[] 用{}初始化 C++98 不支持
//	int* p5 = new int[5]{ 1,2,3 };
//
//	//释放
//	free(p1);
//	delete p2;
//	delete[] p3;//要匹配 如果释放多个
//	delete p4;
//	delete[] p5;
//	
//	//针对内置类型， new/delete 跟malloc/free 没有本质的区别，只有用法的区别
//	//new/delete 用法简化了
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//自定义类型
class A
{
public:
	A(int a = 0)//调用默认构造
		: _a(a)
	{
		cout << "A():" << this << endl;
		 
	}
	~A()
	{
		cout << "~A():" << this << endl;
	}
private:
	int _a;
};
int main()
{
	A* p1 = (A*)malloc(sizeof(A));
	if (p1 == NULL)
	{
		perror("malloc fail"); 
		return 0;
	}
	//1.释放空间
	free(p1);

	//C++
	//1.堆上申请空间  2.调用构造函数初始化
	//A* p2 = new A;
	A* p2 = new A(10);//没有默认构造 也可以传参

	//1.调用析构函数清理对象中资源 2.释放空间
	delete p2;

	A* p3 = new A[10];//创多个对象
	delete[] p3;

	//new失败 不需要检查返回值 失败是抛异常
	try
	{
		/*char* p2 = new char[1024u * 1024u * 1024u * 2 - 1];
		printf("%p\n", p2);*/
		while (1)
		{
			char* p2 = new char[100];
			printf("%p\n", p2); 
		}

	}
	catch (const exception& e) //捕获异常
	{
		cout << e.what() << endl;
	}


	return 0;
}
//结论
//C++ 产生 new/delete 是为自定义类型准备的
//不仅在堆申请出来 还会调用构造 析构函数 初始化和清理
//new delete    new[] delete[] 一定要匹配 

//operator new  在堆上开空间
//operator delete 

//void* __CRTDECL operator new(size_t size) _THROW1(_STD bad_alloc)
//{
//	// try to allocate size bytes
//	void* p;
//	while ((p = malloc(size)) == 0)//封装malloc 符合C++ new 的失败机制  失败抛异常 
//		
//		if (_callnewh(size) == 0)
//		{
//			// report no memory
//			// 如果申请内存失败了，这里会抛出bad_alloc 类型异常
//			static const std::bad_alloc nomem;
//			_RAISE(nomem);
//		}
//	return (p);
//}
//
//
//void operator delete(void* pUserData)
//{
//	_CrtMemBlockHeader* pHead;
//	RTCCALLBACK(_RTC_Free_hook, (pUserData, 0));
//	if (pUserData == NULL)
//		return;
//	_mlock(_HEAP_LOCK);  /* block other threads */
//	__TRY
//		/* get a pointer to memory block header */
//		pHead = pHdr(pUserData);
//	/* verify block type */
//	_ASSERTE(_BLOCK_TYPE_IS_VALID(pHead->nBlockUse));
//	_free_dbg(pUserData, pHead->nBlockUse);
//	__FINALLY
//		_munlock(_HEAP_LOCK);  /* release other threads */
//	__END_TRY_FINALLY
//		return;
//}

//重载一个类专属的 operator new
//struct ListNode
//{
//	int _val;
//	ListNode* _next;
//	//内存池   给所有ListNode 用的
//	static allocator<ListNode>alloc;
//
//	//申请空间
//	void* operator new(size_t n)
//	{
//		cout << "operator new -> STL内存池allocator申请"<<endl;
//		void* obj = alloc.allocate(1);
//		return obj;
//	}
//
//	//释放
//	void operator delete(void* ptr)
//	{
//		cout << "operator delete -> STL内存池allocator申请"<<endl;
//		alloc.deallocate((ListNode*)ptr,1);//传参数 释放几个
//	}
//
//	struct ListNode(int val)
//		:_val(val)
//		,_next(nullptr) 
//	{}
//};
//
////类外面定义
//allocator<ListNode> ListNode::alloc;
//
//int main()
//{
//	//频繁申请ListNode
//	ListNode* node1 = new ListNode(1);
//	ListNode* node2 = new ListNode(2);
//	ListNode* node3 = new ListNode(3);
//
//	delete node1;
//	delete node2;
//	delete node3;
//	return 0;
//}

//new -> operator new + 构造函数
//默认情况下 operator new 使用全局库里面
//每个类可以去实现自己专属 operator new
//实现一个类专属的operator new

//定位new表达式
//对已经使用的空间调用构造函数进行初始化
//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A* p1 = new A;
//	A* p2 = (A*)malloc(sizeof(A));
//	if (p2 == nullptr)
//	{
//		perror("malloc fail");
//	}
//
//	//定位new
//	new(p2)A;
//	new(p2)A(10);//给参数 初始化p2
//
//	return 0;
//}

