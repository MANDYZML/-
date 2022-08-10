#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//C++�ڴ����ʽ

//void Test()
//{
//	int* p1 = (int*)malloc(sizeof(int));
//	free(p1);
//	// 1.malloc/calloc/realloc��������ʲô��
//	int* p2 = (int*)calloc(4, sizeof(int));
//	int* p3 = (int*)realloc(p2, sizeof(int) * 10);
//	// ������Ҫfree(p2)��
//	free(p3);
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//new delete ������

//void Test()
//{
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p2 = new int;
//	//����5��int������
//	int* p3 = new int[5];//����� ��5��int
//	//����1��int���󣬳�ʼ��Ϊ5
//	int* p4 = new int(5);
//
//	//C++11֧��new[] ��{}��ʼ�� C++98 ��֧��
//	int* p5 = new int[5]{ 1,2,3 };
//
//	//�ͷ�
//	free(p1);
//	delete p2;
//	delete[] p3;//Ҫƥ�� ����ͷŶ��
//	delete p4;
//	delete[] p5;
//	
//	//����������ͣ� new/delete ��malloc/free û�б��ʵ�����ֻ���÷�������
//	//new/delete �÷�����
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//�Զ�������
class A
{
public:
	A(int a = 0)//����Ĭ�Ϲ���
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
	//1.�ͷſռ�
	free(p1);

	//C++
	//1.��������ռ�  2.���ù��캯����ʼ��
	//A* p2 = new A;
	A* p2 = new A(10);//û��Ĭ�Ϲ��� Ҳ���Դ���

	//1.�����������������������Դ 2.�ͷſռ�
	delete p2;

	A* p3 = new A[10];//���������
	delete[] p3;

	//newʧ�� ����Ҫ��鷵��ֵ ʧ�������쳣
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
	catch (const exception& e) //�����쳣
	{
		cout << e.what() << endl;
	}


	return 0;
}
//����
//C++ ���� new/delete ��Ϊ�Զ�������׼����
//�����ڶ�������� ������ù��� �������� ��ʼ��������
//new delete    new[] delete[] һ��Ҫƥ�� 

//operator new  �ڶ��Ͽ��ռ�
//operator delete 

//void* __CRTDECL operator new(size_t size) _THROW1(_STD bad_alloc)
//{
//	// try to allocate size bytes
//	void* p;
//	while ((p = malloc(size)) == 0)//��װmalloc ����C++ new ��ʧ�ܻ���  ʧ�����쳣 
//		
//		if (_callnewh(size) == 0)
//		{
//			// report no memory
//			// ��������ڴ�ʧ���ˣ�������׳�bad_alloc �����쳣
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

//����һ����ר���� operator new
//struct ListNode
//{
//	int _val;
//	ListNode* _next;
//	//�ڴ��   ������ListNode �õ�
//	static allocator<ListNode>alloc;
//
//	//����ռ�
//	void* operator new(size_t n)
//	{
//		cout << "operator new -> STL�ڴ��allocator����"<<endl;
//		void* obj = alloc.allocate(1);
//		return obj;
//	}
//
//	//�ͷ�
//	void operator delete(void* ptr)
//	{
//		cout << "operator delete -> STL�ڴ��allocator����"<<endl;
//		alloc.deallocate((ListNode*)ptr,1);//������ �ͷż���
//	}
//
//	struct ListNode(int val)
//		:_val(val)
//		,_next(nullptr) 
//	{}
//};
//
////�����涨��
//allocator<ListNode> ListNode::alloc;
//
//int main()
//{
//	//Ƶ������ListNode
//	ListNode* node1 = new ListNode(1);
//	ListNode* node2 = new ListNode(2);
//	ListNode* node3 = new ListNode(3);
//
//	delete node1;
//	delete node2;
//	delete node3;
//	return 0;
//}

//new -> operator new + ���캯��
//Ĭ������� operator new ʹ��ȫ�ֿ�����
//ÿ�������ȥʵ���Լ�ר�� operator new
//ʵ��һ����ר����operator new

//��λnew���ʽ
//���Ѿ�ʹ�õĿռ���ù��캯�����г�ʼ��
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
//	//��λnew
//	new(p2)A;
//	new(p2)A(10);//������ ��ʼ��p2
//
//	return 0;
//}

