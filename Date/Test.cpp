#define _CRT_SECURE_NO_WARNINGS 1

//构造函数
//1.大部分的类都要自己写构造函数
//2.只有像MyQueue这样类不需要显示写构造函数
//3.每个类最好都要提供默认构造函数

//析构函数--完成资源的释放
//1.一些类需要显示写析构函数--Stack Queue
//2.一些类不需要显示写析构函数
//比如： a:比如Date  没有资源需要清理
//b.MyQueue也可以不写 默认生成的就可以
//默认生成的函数 对内置类型不处理  对自定义类型 会调用它的析构函数


#include<iostream>
using namespace std;
#include"Date.h"

//class A
//{
//public:
//	A(int a = 0)//构造
//		:_a(a)
//	{
//		cout << "A(int a =0)->" << _a << endl;
//	}
//
//	~A()//析构
//	{
//		cout << "~A()->" <<_a << endl;
//	}
//private:
//		int _a;
//};
//
//A aa3(3);//全局对象 最先初始化
//
//void f()
//{
//	static A aa0(0);
//	A aa1(1);//先构造 后析构
//	A aa2(2);//后构造 先析构
//	static A aa4(4);//局部静态对象
//}
//
////构造顺序:3 0 1 2 4
////第二次构造  1 2  static第二次不构造了
////析构顺序  ~2 ~1 ~2 ~1 ~4 ~0 ~3
//
//int main()
//{
//	f();
//	f();
//
//	return 0;
//}

//拷贝
//class A
//{
//public:
//	A(int a = 0)
//	{
//		_a = a;
//		cout << "A(int a =0)->" << _a << endl;
//	}
//
//	A(const A& aa)
//	{
//		_a = aa._a;
//		cout << "A(const A& aa)->" << _a << endl;
//	}
//
//	~A()//析构
//	{
//		cout << "~A()->" << _a << endl;
//	}
//private:
//	int _a;
//};
//
//void func1(A aa)//传值传参
//{
//
//}
//
//void func2(A& aa)//引用传参
//{
//
//}
//
//int main()
//{
//	A aa1(1);
//	//A aa2(aa1);
//	func1(aa1);
//	func2(aa1);
//	return 0;
//}


//日期类
void TestDate1()
{
	//构造一个对象
	Date d1(2022, 7, 24);
	Date d2(d1);//拷贝构造

	Date d3(201, 8, 24);
	d2 = d1 = d3;//赋值运算符重载 d1.operator=(&d1, d3);
}

void TestDate2()
{
	Date d1(2022, 7, 24);
	d1 += 4;
	d1.Print();//(d1+4).Print();

	d1 += 40;//跨月
	d1.Print();//(d1+40).Print();

	d1 += 400;//跨年
	d1.Print(); //(d1 + 400).Print();

	d1 += 4000;//跨闰年
	d1.Print();//(d1+4000).Print();
}

int main()
{
	TestDate1();
	return 0;
}