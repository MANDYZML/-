#define _CRT_SECURE_NO_WARNINGS 1

#include"Date.h"

void Date ::Print()
{
	cout << _year << "/" << _month << "/" << _day << endl;
}

//比较两个日期 
//任何一个类，只需要写一个> == 或者 < ==重载 剩下的比较运算符复用即可
bool Date::operator==(const Date& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

//d1 != d2
bool Date::operator!=(const Date& d)
{
	return !(*this == d);//逻辑取反

}
//d1>d2 this是d1 参数d是d2
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

//加天数
Date Date :: operator+(int day)
{
	//Date ret(*this);
	Date ret = *this;//拷贝构造 不是赋值 两个已经存在的对象才是赋值
	ret += day;

	return ret;
}

//d2 += d1 += 100 支持连续加等 有返回值
Date& Date :: operator+=(int day)
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		//看看是否 大于当前 月的天数 
		// 如果要加的天数大于 现在月的天数
		//进来 要进位
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