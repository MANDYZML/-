#pragma once
#include<iostream>
using namespace std;
//������
//class Date
//{
//public:
//	//����ᱻƵ�����ã�����ֱ�ӷ��������涨��Ϊinline
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		cout << "Date(const Date& d)" << endl;
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//��������� operator��������� �Ǻ�����
//	Date& operator=(const Date& d)//d1 = d3 this ��d1 
//		//d������this ����d3������d1
//	{ 
//		if (this != &d)//��ֹ��d2 = d2���� ��ַһ�� �����ȥ
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//	
//
//		return *this;//*this d1���� 
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};


class Date
{
public:
	// ��ȡĳ��ĳ�µ�����
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

	//����ᱻƵ�����ã�����ֱ�ӷ��������涨��Ϊinline
	Date(int year = 1, int month = 1, int day = 1)
	{
		
		_year = year;
		_month = month;
		_day = day;
	}
	//��������� operator��������� �Ǻ�����
	Date& operator=(const Date& d)//d1 = d3 this ��d1 
		//d������this ����d3������d1
	{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		
	}

	void Print();

	//�Ƚ���������
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