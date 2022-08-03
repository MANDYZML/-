#pragma once
#include<iostream>
using namespace std;
#include<assert.h>
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
	//��Ԫ����-��������ڲ�����ʹ��Date�������˽�б�����Ա
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& out, const Date& d);
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

	//����ᱻƵ�����ã�����ֱ�ӷ��������涨��Ϊinline
	Date(int year = 1, int month = 1, int day = 1)
	{
		
		_year = year;
		_month = month;
		_day = day;

		if (!CheckDate())//����˵���� 32��
		{
			Print();
			cout << "���ڷǷ�" << endl;
		}
	}
	//��������� operator��������� �Ǻ�����
	Date& operator=(const Date& d)//d1 = d3 this ��d1 
		//d������this ����d3������d1
	{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		

	}

	void Print() const;

	//�Ƚ���������
	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;
	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;
	
	Date operator+(int day) const;
	Date& operator+=(int day) ;//����const ��Ϊ�Լ�Ҫ�ı�

	Date operator-(int day) const;
	Date& operator-=(int day);

	Date& operator++();
	Date operator++(int);

	Date& operator--();
	Date operator--(int);

	//�������
	int operator-(const Date& d) const;

private:
	int _year;
	int _month;
	int _day;
};

//����������--���
inline ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "��" << d._month << "��" << d._day << "��" << endl;
	return out;
}

//����ȡ����--����
inline istream& operator>>(istream& out, const Date& d)
{
	in >> d._year >>d._month >> d._day;
	assert(d.CheckDate());

	return in;
}
