#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;

//命名空间
namespace std
{
	void test_vector1()
	{
		vector<int> v1;//无参
		vector<int> v2(10, 1);//带参
		vector<int> v3(v2);//拷贝构造
	}

	void test_vector2()
	{
		//插入数据
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);

		//遍历
		//1.下标 + []
		for (size_t i = 0; i < v1.size(); ++i)
		{
			v1[i]++;
		}
		for (size_t i = 0; i < v1.size(); ++i)
		{
			cout << v1[i] << " ";
		}
		cout << endl;

	   //2.迭代器
		vector<int>::iterator it = v1.begin();
		while (it != v1.end())
		{
			(*it)--;
			cout << *it << " ";
			++it;
		}
		cout << endl;

		//范围for的底层被替换为迭代器
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	//测试vector默认扩容

	void TestVectorExpand()
	{
		size_t sz;
		vector<int> v;
		v.reserve(100);//插入100个数据

		sz = v.capacity();
		cout << "making v grow:\n";
		for (int i = 0; i < 100; ++i)
		{
			v.push_back(i);
			if (sz != v.capacity())
			{
				sz = v.capacity();
				cout << "capacity changed: " << sz << '\n';
			}
		}
	}



	void test_vector3()
	{
		//插入数据
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);

		cout << v1.max_size() << endl;

		TestVectorExpand();
	}

	void test_vector4()
	{
		//插入数据
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		cout << v1.max_size() << endl;

		//3的前面插入30
		vector<int>::iterator pos = find(v1.begin(), v1.end(), 3);
		if (pos != v1.end())
		{
			v1.insert(pos, 30);
		}
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		//删除某个数据
		vector<int>::iterator pos = find(v1.begin(), v1.end(), 3);
		if (pos != v1.end())
		{
			//删除3
			v1.erase(pos);
		}
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	//排序 升序
	void test_vector5()
	{
		//插入数据
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(10 );
		v1.push_back(3);
		v1.push_back(5);
		v1.push_back(9);
		
		sort(v1.begin(), v1.end());

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
		sort(v1.begin(), v1.end());

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		less<int> ls;//默认升序
		greater<int> gt;//降序
		//sort(v1.begin(), v1.end(), gt);
		sort(v1.begin(), v1.end(), greater<int>());

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;


		string s("hello 1515123");
		sort(s.begin(), s.end());//升序
		sort(s.begin(), s.end(), greater<char>());//降序

		cout << s << endl;

		vector<char> v;
		string str;

		//vector<char> 无法替代 string

		vector<string> strV;
		string str1("张三");
		strV.push_back(str1);
		strV.push_back(string("李四"));
		strV.push_back("王五");

		for (const auto& str : strV)
		{
			cout << str << endl;
		}
	}


}

int main()
{
	std::test_vector5();
	return 0;
}