#define _CRT_SECURE_NO_WARNINGS 1

#include"Date.h"

void Date ::Print() const //const ���ε�thisָ������ݣ�Ҳ���Ǳ�֤�˳�Ա�����ڲ������޸ĳ�Ա����
{
	cout << _year << "/" << _month << "/" << _day << endl;
}

//�Ƚ��������� 
//�κ�һ���ֻ࣬��Ҫдһ��> == ���� < ==���� ʣ�µıȽ���������ü���
bool Date::operator==(const Date& d) const
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

//d1 != d2
bool Date::operator!=(const Date& d) const
{
	return !(*this == d);//�߼�ȡ��

}
//d1>d2 this��d1 ����d��d2
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

//������
Date Date :: operator+(int day) const
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

//���ڼ�����
Date Date:: operator-(int day) const
{
	Date ret = *this;
	ret -= day;   
	return ret;
}
Date& Date::operator-=(int day)
{
	_day -= day;
	while (_day <= 0)//һ������û��0��
	{
		--_month;//����¼�û�� ���ϸ���
		if (_month == 0)//��Ҫ������һ��
		{
			--_year;
			_month = 12;//���12�¿�ʼ��
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}

Date& Date::operator--()//ǰ��
{
	return *this -= 1;//���ؼ�֮���ֵ
}
Date Date::operator--(int)//����
{
	Date tmp(*this);
	*this -= 1;
	return tmp;//���ؼ�֮ǰ��ֵ
}

//�������  d1 - d2
int  Date::operator-(const Date& d) const
{
	int flag = 1;//�ͼ���d1 �� d2С
	Date max = *this;//d1
	Date min = d; //d2 
	if (*this < d)//d1С��d2
	{
		max = d;
		min = *this; 
		flag = -1;
	}

	int n = 0;
	while (min != max)
	{
		++min;
		++n;//���˶��ٴ� �Ͳ��˶�����
	}
	return n*flag;
}