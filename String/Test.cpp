#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include<assert.h>
using namespace std;

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

//ģ�� -- ���ͱ��
//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(char& left, char& right)
//{
//	char temp = left;
//	left = right;
//	right = temp;
//}


// ���ͱ�� -- ģ��
//typename ������������T�����ȡ�� Ty K V һ���д��ĸ���ߵ�������ĸ��д
//T ����һ��ģ������(��������)
//template<typename T>
//template<class T> //ģ�����(ģ������)-- ���ƺ�������(��������)
//void Swap(T& left, T& right)//���Ͳ���һ����������
//{
//	T tmp = left;
//	left = right;
//	right = tmp;
//}
//
//int main()
//{
//	int i = 1, j = 2;
//	double x = 1.1, y = 2.2;
//	Swap(i, j);
//	Swap(x, y);
//
//	char m = 'A', n = 'B';
//	Swap(m, n);
//
//	return 0;
//}

//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//
//template<class T>
//T* Func(int n)
//{
//	T* a = new T[n];
//	return a;
//}
//
//template<typename T1, typename T2 >
//T1 Add(const T1& left, const T2& right)
//{
//	return left + right;
//}
//
//int main()
//{
//	//�������Զ����ݣ���ʽʵ����
//	Add(1, 2);
//	//Add(1.1, 2);//����ʵ��������
//	Add((int)1.1, 2);//3
//	Add(1.1, (double)2);//3.1
//
//	//��ʾʵ����
//	cout << Add<int>(1.1, 2) << endl;//<>ָ��T����
//	cout << Add<double>(1.1, 2) << endl;
//
//	//��������ʽʵ�������ܵ���
//	Func<A>(10);
//
//	Add(1.1, 2);
//	return 0;
//}

// ר�Ŵ���int�ļӷ�����
//int Add(int left, int right)
//{
//	return left + right;
//}
//// ͨ�üӷ�����
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//
//int main()
//{
//	// 
//	cout << Add(1, 2) << endl;
//	cout << Add(1.1, 2.2) << endl;
//
//	return 0;
//}

//��ģ��
template<class T>
class Stack
{
public:
	Stack(size_t capacity = 4)
		:_a(nullptr)
		,_capacity(0)
		,_top(0)
	{
		if (capacity > 0)
		{
			_a = new T[capacity];
			_capacity = capacity;
			_top = 0;
		}
	}

	~Stack()
	{
		delete[] _a;
		_a = nullptr;
		_capacity = _top = 0;
	}

	void Push(const T& x);

	void Pop()
	{
		assert(_top > 0);
		--_top;
	}

	bool Empty()
	{
		return _top == 0;
	}

	const T& Top()//ȡջ��Ԫ��
	{
		assert(_top > 0);
		return _a[_top - 1];
	}

private:
	T* _a;
	size_t top;
	size_t capacity;
};

template<class T>
void Stack<T>::Push(const T& x)
{
	if (_top == _capacity)//����費��Ҫ����
	{
		size_t newCapacity = _capacity == 0 ? 4 : _capacity * 2;
		//1.���¿ռ�
		T* tmp = new T[newCapacity];
		if (_a)//ԭ���ռ䲻Ϊ��
		{
			memcpy(tmp, _a, sizeof(T) * _top);//2.��ԭ�����ݿ��������ݵ��¿ռ�
			//_a �ɿռ� tmp�¿ռ�
			delete[]_a;//3.�ͷžɿռ�
		}
		_a = tmp;//ָ���¿ռ�
		_capacity = newCapacity;

	}
	_a[_top] = x;
	++_top;
}
//ģ����ͬһ�ļ����ǿ��������Ͷ�������

int main()
{

	try
	{
		//��ģ�嶼����ʾʵ����
		//��Ȼ����һ����ģ�壬��������������
		Stack<int> st1;
		Stack<char> st2;
		//Ҫ��100�����ݣ��������ʱ��������
		Stack<int> st3(100);
		Stack<int> st4(0);

	}
	catch (const exception* e)
	{
		cout << e.what() << endl;
	}

	return 0;

}