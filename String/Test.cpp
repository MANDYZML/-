#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include<assert.h>
using namespace std;

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

//模板 -- 泛型编程
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


// 泛型编程 -- 模板
//typename 后面类型名字T是随便取的 Ty K V 一般大写字母或者单词首字母大写
//T 代表一个模板类型(虚拟类型)
//template<typename T>
//template<class T> //模板参数(模板类型)-- 类似函数参数(参数对象)
//void Swap(T& left, T& right)//类型不是一个具体类型
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
//	//编译器自动推演，隐式实例化
//	Add(1, 2);
//	//Add(1.1, 2);//推演实例化报错
//	Add((int)1.1, 2);//3
//	Add(1.1, (double)2);//3.1
//
//	//显示实例化
//	cout << Add<int>(1.1, 2) << endl;//<>指定T类型
//	cout << Add<double>(1.1, 2) << endl;
//
//	//必须显显式实例化才能调用
//	Func<A>(10);
//
//	Add(1.1, 2);
//	return 0;
//}

// 专门处理int的加法函数
//int Add(int left, int right)
//{
//	return left + right;
//}
//// 通用加法函数
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

//类模板
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

	const T& Top()//取栈顶元素
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
	if (_top == _capacity)//检查需不需要扩容
	{
		size_t newCapacity = _capacity == 0 ? 4 : _capacity * 2;
		//1.开新空间
		T* tmp = new T[newCapacity];
		if (_a)//原来空间不为空
		{
			memcpy(tmp, _a, sizeof(T) * _top);//2.把原来数据拷贝到扩容的新空间
			//_a 旧空间 tmp新空间
			delete[]_a;//3.释放旧空间
		}
		_a = tmp;//指向新空间
		_capacity = newCapacity;

	}
	_a[_top] = x;
	++_top;
}
//模板在同一文件中是可以声明和定义分离的

int main()
{

	try
	{
		//类模板都是显示实例化
		//虽然用了一个类模板，但是是两个类型
		Stack<int> st1;
		Stack<char> st2;
		//要存100个数据，避免插入时扩容消耗
		Stack<int> st3(100);
		Stack<int> st4(0);

	}
	catch (const exception* e)
	{
		cout << e.what() << endl;
	}

	return 0;

}