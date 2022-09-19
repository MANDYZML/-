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

	auto pos = find(lt.begin(), lt.end(), 3);//����һ��ֵ
	if (pos != lt.end())
	{
		//pos����ʧЧ
		lt.insert(pos, 30);//posλ�ò���30
		*pos *= 100;
	}
	

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;


	//ɾ������
	pos = find(lt.begin(), lt.end(), 3);//����һ��ֵ
	if (pos != lt.end())
	{
		//pos��ʧЧ
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

	lt.remove(3); //ɾ�����е�3

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