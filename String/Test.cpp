#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include<assert.h>
using namespace std;

//class A
//{
//public:
//	A(int a = 0)//调用默认构造
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//
//	}
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//private:
//	int _a;
//};

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
//template<class T>
//class Stack
//{
//public:
//	Stack(size_t capacity = 4)
//		:_a(nullptr)
//		,_capacity(0)
//		,_top(0)
//	{
//		if (capacity > 0)
//		{
//			_a = new T[capacity];
//			_capacity = capacity;
//			_top = 0;
//		}
//	}
//
//	~Stack()
//	{
//		delete[] _a;
//		_a = nullptr;
//		_capacity = _top = 0;
//	}
//
//	void Push(const T& x);
//
//	void Pop()
//	{
//		assert(_top > 0);
//		--_top;
//	}
//
//	bool Empty()
//	{
//		return _top == 0;
//	}
//
//	const T& Top()//取栈顶元素
//	{
//		assert(_top > 0);
//		return _a[_top - 1];
//	}
//
//private:
//	T* _a;
//	size_t top;
//	size_t capacity;
//};
//
//template<class T>
//void Stack<T>::Push(const T& x)
//{
//	if (_top == _capacity)//检查需不需要扩容
//	{
//		size_t newCapacity = _capacity == 0 ? 4 : _capacity * 2;
//		//1.开新空间
//		T* tmp = new T[newCapacity];
//		if (_a)//原来空间不为空
//		{
//			memcpy(tmp, _a, sizeof(T) * _top);//2.把原来数据拷贝到扩容的新空间
//			//_a 旧空间 tmp新空间
//			delete[]_a;//3.释放旧空间
//		}
//		_a = tmp;//指向新空间
//		_capacity = newCapacity;
//
//	}
//	_a[_top] = x;
//	++_top;
//}
////模板在同一文件中是可以声明和定义分离的
//
//int main()
//{
//
//	try
//	{
//		//类模板都是显示实例化
//		//虽然用了一个类模板，但是是两个类型
//		Stack<int> st1;
//		Stack<char> st2;
//		//要存100个数据，避免插入时扩容消耗
//		Stack<int> st3(100);
//		Stack<int> st4(0);
//
//	}
//	catch (const exception* e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//
//}

//string
#include <iostream>
#include<string>
using namespace std;

void test_string1()
{
	string s1;//无参构造函数
	string s2("hello world!!!");//带参数
	cout << s1 << endl;
	cout << s2 << endl;

	/*cin >> s1 >> s2; //输入
	cout << s1 << endl; //输出
	cout << s2 << endl;*/

	//拷贝构造
	string s3(s2);
	cout << s3 << endl;

	//部分拷贝构造
	string s4(s2, 6, 5);//从第六个开始 拷贝5个
	cout << s4 << endl;

	//拷贝个数超过字符串原有个数 那就 有多少拷贝多少
	string s5(s2, 6, 15);
	cout << s5 << endl;

	//如果第三个参数 有缺省值 npos= -1 整型最大值
	string s6(s2, 6);
	cout << s6 << endl;

	//用前5个初始化对象 
	string s7("hello world",5);//hello
	cout << s7 << endl;

	//100个x初始化
	string s8(100, 'x');
	cout << s8 << endl;
}

//赋值
void test_string2()
{
	string s1;
	string s2 = "hello world!!!";//构造+拷贝构造 -> 优化 -- 直接构造

	s1 = s2;//拷贝赋值
	s1 = "xxxx"; //字符串赋值
	s1 = 'y'; //字符赋值
}

void test_string3()
{
	string s1("hello world");
	//遍历字符串
	cout << s1[0] << endl;
	s1[0] = 'x';
	cout << s1[0] << endl;//把h修改成x
	cout << s1 << endl;//xello world

	//要求遍历 string 每个字符+1
	//for (size_t i = 0; i < s1.length(); ++i)
	for (size_t i = 0; i < s1.size(); ++i)
	{
		s1[i]++;
	}
	cout << s1 << endl;//yfmmp!xpsme

	const string s2("world");
	for (size_t i = 0; i < s2.size(); ++i)
	{
		//s2[i]++;
		cout << s2[i] << " ";//打印每个字符
	}
	cout << endl; 
	cout << s2 << endl;

	//内部会检查越界
}

//迭代器-- iterator(像指针一样的类型 以及用法)  遍历
void test_string4()
{
	string s("hello");
	string::iterator it = s.begin();//返回第一个位置的迭代器
	while (it != s.end())//end 返回最后一个位置的下一个 也就是\0
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//范围for -- 自动迭代(++) 自动判断结束
	//依次取s中的每个字符 赋值给ch
	/*for (auto ch : s)
	{
		ch++;
		cout << ch << " ";
	}*/
	for (auto& ch : s)
	{
		ch++;
		cout << ch << " ";
	}
	cout << endl;

	cout << s << endl;

	//列表
	/*List<int> lt(10, 1);
	List<int> :: iterator lit = lt.begin();
	while (lit != lt.end())
	{
		cout << *lit << " ";
		++lit;
	}
	cout << endl;*/

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	//范围for底层其实就是迭代器
}

void PrintString(string& str)
{
	//const 迭代器 只能读 不能写
	//string::const_iterator it = str.begin();
	auto it = str.begin();
	while (it != str.end())
	{
		//*it = 'x'; //报错
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
//反向迭代器
void test_string5()
{
	string s("hello");
	string::reverse_iterator rit = s.rbegin(); //指向o
	while (rit != s.rend())//指向最后一个数据的前一个位置 也就是 h的前一个位置
	{
		cout << *rit << " ";
		++rit;// hello 从后往前走
	}
	cout << endl;

	PrintString(s);
}

//迭代器
//iterator/ const_iterator
//reverse_iteator/const_reverse_iterator

void test_string6()
{
   //插入字符
	string s("hello");
	s.push_back('-');
	s.push_back('-');
	s.append("world");

	cout << s << endl;//hello--world

	string str("我来了");
	s += '@';
	s += str;
	s += "!!!"; 
	cout << s << endl;

	s.append(++str.begin(), --str.end());//又添加一次
	cout << s << endl;

	string copy(++s.begin(), --s.end());
	cout << copy << endl;
}

void test_string7()
{
	string s1;
	string s2("1111111111111");
	cout << s1.max_size() << endl;
	cout << s2.max_size() << endl;


	cout << s1.capacity() << endl;
	cout << s2.capacity() << endl; 
}

int main()
{
	//test_string1();
	//test_string2();
	//test_string3();
	//test_string4();
	//test_string5();
	//test_string6();
	test_string7();
	return 0;
}