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
//void test_string4()
//{
//	string s("hello");
//	string::iterator it = s.begin();//���ص�һ��λ�õĵ�����
//	while (it != s.end())//end �������һ��λ�õ���һ�� Ҳ����\0
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	//��Χfor -- �Զ�����(++) �Զ��жϽ���
//	//����ȡs�е�ÿ���ַ� ��ֵ��ch
//	/*for (auto ch : s)
//	{
//		ch++;
//		cout << ch << " ";
//	}*/
//	for (auto& ch : s)
//	{
//		ch++;
//		cout << ch << " ";
//	}
//	cout << endl;
//
//	cout << s << endl;
//
//	//�б�
//	/*List<int> lt(10, 1);
//	List<int> :: iterator lit = lt.begin();
//	while (lit != lt.end())
//	{
//		cout << *lit << " ";
//		++lit;
//	}
//	cout << endl;*/
//
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	//��Χfor�ײ���ʵ���ǵ�����
//}

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

//void test_string7()
//{
//	string s1;
//	string s2("1111111111111");
//	cout << s1.max_size() << endl;
//	cout << s2.max_size() << endl;
//
//	//������С
//	cout << s1.capacity() << endl;
//	cout << s2.capacity() << endl; 
//
//	//reverse ����
//	//s.reserve(1000); //���� ���ռ�
//	s.resize(1000)  //���ռ�+��ʼ��
//}

void test_string8()
{
	//ÿ���ո��λ�ò���һ�� %
	string str("wo lai le");
	//for (size_t i = 0; i < str.size();)
	//{
	//	if (str[i] == ' ')
	//	{
	//		str.insert(i, "%20");//���ո�λ�ò���%20
	//		i += 4;
	//	}
	//	else
	//	{
	//		//�����ڿո�
	//		++i;
	//	}
	//	
	//}

	//for (size_t i = 0; i < str.size();++i)
	//{
	//	if (str[i] == ' ')
	//	{
	//		str.insert(i, "%20");//���ո�λ�ò���%20
	//		i += 3;
	//	}

	//}
	/*cout << str << endl;*/


	//ɾ���ַ� �ַ������ ɾ����Χ�� ���ж���ɾ����
//	for (size_t i = 0; i < str.size(); ++i)
//	{
//		if (str[i] == ' ')
//		{
//			str.erase(i, 1);//�ӿո�ʼɾ ɾһ��
//		}
//	}
//	cout << str << endl;

	//�Կռ任ʱ��  O(N)
	string newstr;
	for (size_t i = 0; i < str.size(); ++i)//�����ַ���
	{
		if (str[i] != ' ')
		{
			newstr += str[i];
		}
		else
		{
			//���ڿո�Ͳ���
			newstr += "20%";
		}
	}
	cout << newstr << endl;
}


void test_string9()
{
	//��c���ļ�
	string  filename("test.cpp");
	cout << filename << endl;
	cout << filename.c_str() << endl;


	FILE* fout = fopen(filename.c_str(), "r");
	assert(fout);
	char ch = fgetc(fout);
	while (ch != EOF)
	{
		cout << ch;
		ch = fgetc(fout);//��ӡ����test.cpp�еĴ���
	}
}

void test_string10()
{
	//��c���ļ�
	string  filename("test.cpp");
	cout << filename << endl;
	cout << filename.c_str() << endl;

	filename += '\0';
	filename += "string.cpp";
	cout << filename << endl; //��string ���� size Ϊ׼
	cout << filename.c_str() << endl;//�Գ����ַ������� \0Ϊ׼ ����\0����ֹ

	cout << filename.size() << endl;
	string copy = filename;
	cout << copy << endl << endl;
	
	for (unsigned ch = 0; ch < 128; ++ch)
	{
		cout << ch;
	}
	cout << endl;
	cout << "\0" << endl;//��ӡ������ �����ַ� \ 0
}

void DealUrl(const string& url)
{
	//��һ������ ȡЭ�鳤��
	size_t pos1 = url.find("://");
	if (pos1 == string::npos)
	{
		cout << "�Ƿ�url" << endl;
		return;
	}
	string protocol = url.substr(0, pos1);//ȡЭ�鳤��
	cout << protocol << endl;

	//�ڶ����� -- ȡ����
	size_t pos2 = url.find('/', pos1 + 3);//����һ��/
	if (pos2 == string::npos)
	{
		cout << "�Ƿ�url" << endl;
		return;
	}

	//��pos1+3 ��ʼȡ ȡ����һ��/λ��
	string domain = url.substr(pos1 + 3, pos2 - pos1 - 3);
	cout << domain << endl;

	//�������� -- ��Դ��λ
	string uri = url.substr(pos2 + 1);//ȡ����β
	cout << uri << endl;
}
void test_string11()
{
	//���ļ���׺
	string filename("test.cpp.tar.zip");
	//size_t pos = filename.find('.');//����. ����
	//if (pos != string::npos)
	//{
	//	//��posλ�ÿ�ʼȡ length������
	//	//.size ���Ǻ�׺���� .cpp
	//	//string suff = filename.substr(pos, filename.size() - pos);
	//	string suff = filename.substr(pos);//�ҵ�pos�� ֱ��ȡ��ĩβ
	//	cout << suff << endl;
	//}

	//ֻȡ���һ����׺
	size_t pos = filename.rfind('.');//������ ȡ���һ����׺
	if (pos != string::npos)
	{
		//��posλ�ÿ�ʼȡ length������
		//.size ���Ǻ�׺���� .cpp
		//string suff = filename.substr(pos, filename.size() - pos);
		string suff = filename.substr(pos);//�ҵ�pos�� ֱ��ȡ��ĩβ
		cout << suff << endl;
	}

	string url1 = "https://leetcode.cn/problems/reverse-only-letters/submissions/";
	string url2 = "file:///C:/Users/manli/OneDrive/%E6%A1%8C%E9%9D%A2/IT%E5%90%84%E7%A7%8D%E8%AF%BE%E4%BB%B6/%E6%AF%94%E7%89%B9/C++%E8%AF%BE%E4%BB%B6/C++%E8%AF%BE%E4%BB%B6--2022%E4%BF%AE%E8%AE%A2/C++%E8%AF%BE%E4%BB%B6--2022%E4%BF%AE%E8%AE%A2/C++%E5%88%9D%E9%98%B6%E8%AF%BE%E4%BB%B6/Lesson08---string.pdf";

	//����ַ�ָ����������
	DealUrl(url1);
	
}

int main()
{
	//test_string1();
	//test_string2();
	//test_string3();
	//test_string4();
	//test_string5();
	//test_string6();
	//test_string7();
	//test_string8();
	//test_string9();
	//test_string10();
	test_string11();
	return 0;
}