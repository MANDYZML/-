#define _CRT_SECURE_NO_WARNINGS 1

#include"Date.h"

void Date ::Print() const //const 修饰的this指向的内容，也就是保证了成员函数内部不会修改成员变量
{
	cout << _year << "/" << _month << "/" << _day << endl;
}

//比较两个日期 
//任何一个类，只需要写一个> == 或者 < ==重载 剩下的比较运算符复用即可
bool Date::operator==(const Date& d) const
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

//d1 != d2
bool Date::operator!=(const Date& d) const
{
	return !(*this == d);//逻辑取反

}
//d1>d2 this是d1 参数d是d2
bool Date::operator>(const Date& d) const
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
bool Date :: operator>=(const Date& d) const
{
	return (*this > d) || (*this == d);
}
bool Date :: operator<(const Date& d) const
{
	return !(*this >= d);
}
bool Date :: operator<=(const Date& d) const
{
	return !(*this > d);
}

//加天数
Date Date :: operator+(int day) const
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

//日期减天数
Date Date:: operator-(int day) const
{
	Date ret = *this;
	ret -= day;   
	return ret;
}
Date& Date::operator-=(int day)
{
	_day -= day;
	while (_day <= 0)//一个月里没有0号
	{
		--_month;//这个月减没了 减上个月
		if (_month == 0)//就要减到上一年
		{
			--_year;
			_month = 12;//变成12月开始减
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}

Date& Date::operator--()//前置
{
	return *this -= 1;//返回减之后的值
}
Date Date::operator--(int)//后置
{
	Date tmp(*this);
	*this -= 1;
	return tmp;//返回减之前的值
}

//日期相减  d1 - d2
int  Date::operator-(const Date& d) const
{
	int flag = 1;//就假设d1 大 d2小
	Date max = *this;//d1
	Date min = d; //d2 
	if (*this < d)//d1小于d2
	{
		max = d;
		min = *this; 
		flag = -1;
	}

	int n = 0;
	while (min != max)
	{
		++min;
		++n;//加了多少次 就差了多少天
	}
	return n*flag;
}