#define _CRT_SECURE_NO_WARNINGS 1

//兼容c语言
#include<stdio.h>
#include<stdlib.h> //rand会报错--命名冲突  库里有这个函数

//int main()
//{
//	printf("hello world\n");
//	return 0;
//}

//c++写
//#include<iostream>
//using namespace std;//std是c++标准库的命名空间
//先在全局去找，如果没有还会在展开的std域中去找
//
//int main()
//{
//	std::cout << "hello world" std::<<endL;
//}

//命名空间域 --namespace
//namespace  bit //命名一个空间叫bit
//{
//	int rand = 0;//属于这个空间的全局变量
//}
//
//int main()
//{
//	printf("%d\n", rand);//这个是访问全局rand--也就是库里的  
//	printf("%d\n", bit::rand);//指定访问命名空间
//
//	return 0;
//}

//域
//int a = 0;//全局
//int main()
//{
//	int a = 1;//局部
//	printf("%d\n", a);//就近原则 先找局部  打印1
//	                   //局部没有找全局
//
//	//:: 域作用限定符
//	printf("%d\n", ::a);//去:: 左边域去找 空白就是 全局域
//	return 0;
//}


//命名空间还能定义函数
//namespace sql //命名空间还能嵌套
//{
//	int a = 0;
//
//	namespace  bit //命名一个空间叫bit
//	{
//		int rand = 0;//属于这个空间的全局变量
//		void func()
//		{
//			printf("func()\n");//定义函数
//		}
//		struct TreeNode //定义类型
//		{
//			struct TreeNode* left;
//			struct TreeNode* right;
//			int val;
//		};
//	}
//}
//int main()
//{
//	printf("%d\n", rand);//这个是访问全局rand--也就是库里的  
//	printf("%d\n", sql::bit::rand);//指定访问命名空间
//	
//	sql::bit::func();
//	struct sql::bit::TreeNode node;//到指定空间找
//	return 0;
//}

#include<iostream> //io流
//using namespace std;//std是c++标准库的命名空间
//先在全局去找，如果没有还会在展开的std域中去找

//展开常用的
//using std::cout;
//using std::cin;
//
//int main()
//{
//	// << 流插入
//	std::cout << "hello world" std::<<endL;//等价于换行
//	std::cout << "hello world" std::<<"\n ";
//
//	//自动识别类型
//	int i = 11;
//	double d = 11.11;
//	printf("%d,%f", i, d);//c语言
//	std::cout << i << d << std::endL;//不需要指定类型
//
//	//输入也是  >> 流提取
//	scanf("%d%lf", &i, &d);
//	std::cin >> i >> d;
//}   



//类和对象
#include<iostream> 
using namespace std;

//类的作用域
//class Person
//{
//public:
//	void PrintPersonInfo();
//private:
//	char _name[2];
//	char _gender[3];
//	int _age;
//}; //{} 括起来的都是一个域
//
////函数 PrintPesonInfo 是属于Person 这个类的局部域
////在类体外定义成员时 需要使用 :: 作用域操作符指明成员属于哪个类域
//void Person::PrintPersonInfo()
//{
//	cout << _name << " " << _gender << " " << _age < endl;
//}
//
////类的实例化
//class Person
//{
//public:
//	void PrintPersonInfo(); //函数声明
//private:
//	char _name[2];        //声明
//	char _gender[3];
//	int _age;
//}; 
//void Person::PrintPersonInfo()  //定义
//{
//	cout << _name << " " << _gender << " " << _age < endl;
//}

//this指针

//单词和单词之间首字母大写间隔  --驼峰法 GetYear
//单词全部小写 单词之间用 _ 分割  get_year
//class Date
//{
//public:
//	void Init(int year, int month, int day)
//   //void Init(Date* const this, int year, int month, int day)
//		//const修饰的是 this指针本身 不能被修改
//		//指向的内容可以被修改
//	{
//		//初始化
//		_year = year;  //this->_year= year;
//		_month = month; //this->_month = month;
//		_day = day; //this->_day = day;
//	}
//
//	void Print()//void Print(Date* const this)
//	{
//		//cout <<this->_year << "-" << this->_month << "-" << this->_day << endl;
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;   //声明 
//	int _month;
//	int _day;
//
//};
//
////实参和形参位置不能显示传递和接收this指针
////但是可以在成员函数的内部使用this指针
//int main()
//{
//	Date d1;
//	d1.Init(2022, 7, 17);//d1.Init(&d1,2022, 7, 17);
//
//	Date d2;
//	d2.Init(2022, 7, 18);//d1.Init(&d2,2022, 7, 17);
//
//	d1.Print(); //d1.Print(&d1);
//	d2.Print();//d2.Print(&d2);
//	return 0;
//}

//构造函数
class Date
{
public:
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1, d2;
	d1.SetDate(2018, 5, 1);
	d1.Display();
	Date d2;
	d2.SetDate(2018, 7, 1);
	d2.Display();
	return 0;
}
