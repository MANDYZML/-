#pragma once
#include<iostream>
using namespace std;
//日期类
//class Date
//{
//public:
//	//构造会被频繁调用，所以直接放在类里面定义为inline
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		cout << "Date(const Date& d)" << endl;
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//运算符重载 operator加上运算符 是函数名
//	Date& operator=(const Date& d)//d1 = d3 this 是d1 
//		//d赋给了this 就是d3赋给了d1
//	{ 
//		if (this != &d)//防止像d2 = d2这种 地址一样 不会进去
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//	
//
//		return *this;//*this d1对象 
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};


class Date
{
public:
	// 获取某年某月的天数
	int GetMonthDay(int year, int month)
	{
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];
		if (month == 2
			&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			day += 1;
		}
		return day;
	}

	//构造会被频繁调用，所以直接放在类里面定义为inline
	Date(int year = 1, int month = 1, int day = 1)
	{
		
		_year = year;
		_month = month;
		_day = day;
	}
	//运算符重载 operator加上运算符 是函数名
	Date& operator=(const Date& d)//d1 = d3 this 是d1 
		//d赋给了this 就是d3赋给了d1
	{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		
	}

	void Print();

	//比较两个日期
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	
	Date operator+(int day);
	Date& operator+=(int day);
private:
	int _year;
	int _month;
	int _day;
};