#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include<assert.h>
using namespace std;

//class A
//{
//public:
//	A(int a = 0)//����Ĭ�Ϲ���
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
//	const T& Top()//ȡջ��Ԫ��
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
//	if (_top == _capacity)//����費��Ҫ����
//	{
//		size_t newCapacity = _capacity == 0 ? 4 : _capacity * 2;
//		//1.���¿ռ�
//		T* tmp = new T[newCapacity];
//		if (_a)//ԭ���ռ䲻Ϊ��
//		{
//			memcpy(tmp, _a, sizeof(T) * _top);//2.��ԭ�����ݿ��������ݵ��¿ռ�
//			//_a �ɿռ� tmp�¿ռ�
//			delete[]_a;//3.�ͷžɿռ�
//		}
//		_a = tmp;//ָ���¿ռ�
//		_capacity = newCapacity;
//
//	}
//	_a[_top] = x;
//	++_top;
//}
////ģ����ͬһ�ļ����ǿ��������Ͷ�������
//
//int main()
//{
//
//	try
//	{
//		//��ģ�嶼����ʾʵ����
//		//��Ȼ����һ����ģ�壬��������������
//		Stack<int> st1;
//		Stack<char> st2;
//		//Ҫ��100�����ݣ��������ʱ��������
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
	string s1;//�޲ι��캯��
	string s2("hello world!!!");//������
	cout << s1 << endl;
	cout << s2 << endl;

	/*cin >> s1 >> s2; //����
	cout << s1 << endl; //���
	cout << s2 << endl;*/

	//��������
	string s3(s2);
	cout << s3 << endl;

	//���ֿ�������
	string s4(s2, 6, 5);//�ӵ�������ʼ ����5��
	cout << s4 << endl;

	//�������������ַ���ԭ�и��� �Ǿ� �ж��ٿ�������
	string s5(s2, 6, 15);
	cout << s5 << endl;

	//������������� ��ȱʡֵ npos= -1 �������ֵ
	string s6(s2, 6);
	cout << s6 << endl;

	//��ǰ5����ʼ������ 
	string s7("hello world",5);//hello
	cout << s7 << endl;

	//100��x��ʼ��
	string s8(100, 'x');
	cout << s8 << endl;
}

//��ֵ
void test_string2()
{
	string s1;
	string s2 = "hello world!!!";//����+�������� -> �Ż� -- ֱ�ӹ���

	s1 = s2;//������ֵ
	s1 = "xxxx"; //�ַ�����ֵ
	s1 = 'y'; //�ַ���ֵ
}

void test_string3()
{
	string s1("hello world");
	//�����ַ���
	cout << s1[0] << endl;
	s1[0] = 'x';
	cout << s1[0] << endl;//��h�޸ĳ�x
	cout << s1 << endl;//xello world

	//Ҫ����� string ÿ���ַ�+1
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
		cout << s2[i] << " ";//��ӡÿ���ַ�
	}
	cout << endl; 
	cout << s2 << endl;

	//�ڲ�����Խ��
}

//������-- iterator(��ָ��һ�������� �Լ��÷�)  ����
void test_string4()
{
	string s("hello");
	string::iterator it = s.begin();//���ص�һ��λ�õĵ�����
	while (it != s.end())//end �������һ��λ�õ���һ�� Ҳ����\0
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//��Χfor -- �Զ�����(++) �Զ��жϽ���
	//����ȡs�е�ÿ���ַ� ��ֵ��ch
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

	//�б�
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

	//��Χfor�ײ���ʵ���ǵ�����
}

void PrintString(string& str)
{
	//const ������ ֻ�ܶ� ����д
	//string::const_iterator it = str.begin();
	auto it = str.begin();
	while (it != str.end())
	{
		//*it = 'x'; //����
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
//���������
void test_string5()
{
	string s("hello");
	string::reverse_iterator rit = s.rbegin(); //ָ��o
	while (rit != s.rend())//ָ�����һ�����ݵ�ǰһ��λ�� Ҳ���� h��ǰһ��λ��
	{
		cout << *rit << " ";
		++rit;// hello �Ӻ���ǰ��
	}
	cout << endl;

	PrintString(s);
}

//������
//iterator/ const_iterator
//reverse_iteator/const_reverse_iterator

void test_string6()
{
   //�����ַ�
	string s("hello");
	s.push_back('-');
	s.push_back('-');
	s.append("world");

	cout << s << endl;//hello--world

	string str("������");
	s += '@';
	s += str;
	s += "!!!"; 
	cout << s << endl;

	s.append(++str.begin(), --str.end());//�����һ��
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