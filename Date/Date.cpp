#define _CRT_SECURE_NO_WARNINGS 1

#include"Date.h"

void Date ::Print()
{
	cout << _year << "/" << _month << "/" << _day << endl;
}

//�Ƚ��������� 
//�κ�һ���ֻ࣬��Ҫдһ��> == ���� < ==���� ʣ�µıȽ���������ü���
bool Date::operator==(const Date& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

//d1 != d2
bool Date::operator!=(const Date& d)
{
	return !(*this == d);//�߼�ȡ��

}
//d1>d2 this��d1 ����d��d2
bool Date::operator>(const Date& d)
{
	if (_year > d._year)
	{
		return true;
    }
	else if (_year == d._year && _month > d._month)
	{
		return true;
	}
	else if (_year == d._year && _month == d._month && _day > d._day)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Date :: operator>=(const Date& d)
{
	return (*this > d) || (*this == d);
}
bool Date :: operator<(const Date& d)
{
	return !(*this >= d);
}
bool Date :: operator<=(const Date& d)
{
	return !(*this > d);
}

//������
Date Date :: operator+(int day)
{
	//Date ret(*this);
	Date ret = *this;//�������� ���Ǹ�ֵ �����Ѿ����ڵĶ�����Ǹ�ֵ
	ret += day;

	return ret;
}

//d2 += d1 += 100 ֧�������ӵ� �з���ֵ
Date& Date :: operator+=(int day)
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		//�����Ƿ� ���ڵ�ǰ �µ����� 
		// ���Ҫ�ӵ��������� �����µ�����
		//���� Ҫ��λ
		_day -= GetMonthDay(_year, _month);
		++_month;
		if (_month == 13)
		{
			_year++;
			_month == 1;
		}
	}
	return *this;
}