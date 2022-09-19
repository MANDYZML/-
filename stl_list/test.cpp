#define _CRT_SECURE_NO_WARNINGS 1 
#include<iostream>
#include<list>
using namespace std;

#include"list.h"


void test_list1()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);

	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl; 

	it = lt.begin();
	while (it != lt.end())
	{
		*it *= 2;
		++it;
	}
	cout << endl;

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;




	lt.push_front(10);
	lt.push_front(20);
	lt.push_front(30);
	lt.push_front(40);
	
	lt.pop_back();
	lt.pop_back();
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}


void test_list2()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);

	auto pos = find(lt.begin(), lt.end(), 3);//查找一个值
	if (pos != lt.end())
	{
		//pos不会失效
		lt.insert(pos, 30);//pos位置插入30
		*pos *= 100;
	}
	

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;


	//删除数据
	pos = find(lt.begin(), lt.end(), 3);//查找一个值
	if (pos != lt.end())
	{
		//pos会失效
		lt.erase(pos);
	}

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_list3()
{ 
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.remove(3); //删除所有的3

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}
int main()
{
	test_list1();
	bit::test_list1();
	return 0;
}