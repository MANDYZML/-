#pragma once
#include<iostream>
using namespace std;
#include<assert.h>
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
	//友元函数-这个函数内部可以使用Date对象访问私有保护成员
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& out, const Date& d);
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

	bool CheckDate()
	{
		if (_year >= 1
			&& _month > 0 && _month < 13
			&& _day >0 && _day <= GetMonthDay(_year, _month))
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	//构造会被频繁调用，所以直接放在类里面定义为inline
	Date(int year = 1, int month = 1, int day = 1)
	{
		
		_year = year;
		_month = month;
		_day = day;

		if (!CheckDate())//比如说输入 32号
		{
			Print();
			cout << "日期非法" << endl;
		}
	}
	//运算符重载 operator加上运算符 是函数名
	Date& operator=(const Date& d)//d1 = d3 this 是d1 
		//d赋给了this 就是d3赋给了d1
	{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		

	}

	void Print() const;

	//比较两个日期
	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;
	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;
	
	Date operator+(int day) const;
	Date& operator+=(int day) ;//不加const 因为自己要改变

	Date operator-(int day) const;
	Date& operator-=(int day);

	Date& operator++();
	Date operator++(int);

	Date& operator--();
	Date operator--(int);

	//日期相减
	int operator-(const Date& d) const;

private:
	int _year;
	int _month;
	int _day;
};

//流插入重载--输出
inline ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
	return out;
}

//流提取重载--输入
inline istream& operator>>(istream& out, const Date& d)
{
	in >> d._year >>d._month >> d._day;
	assert(d.CheckDate());

	return in;
}
