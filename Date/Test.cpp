#define _CRT_SECURE_NO_WARNINGS 1

//���캯��
//1.�󲿷ֵ��඼Ҫ�Լ�д���캯��
//2.ֻ����MyQueue�����಻��Ҫ��ʾд���캯��
//3.ÿ������ö�Ҫ�ṩĬ�Ϲ��캯��

//��������--�����Դ���ͷ�
//1.һЩ����Ҫ��ʾд��������--Stack Queue
//2.һЩ�಻��Ҫ��ʾд��������
//���磺 a:����Date  û����Դ��Ҫ����
//b.MyQueueҲ���Բ�д Ĭ�����ɵľͿ���
//Ĭ�����ɵĺ��� ���������Ͳ�����  ���Զ������� �����������������


#include<iostream>
using namespace std;
#include"Date.h"

//class A
//{
//public:
//	A(int a = 0)//����
//		:_a(a)
//	{
//		cout << "A(int a =0)->" << _a << endl;
//	}
//
//	~A()//����
//	{
//		cout << "~A()->" <<_a << endl;
//	}
//private:
//		int _a;
//};
//
//A aa3(3);//ȫ�ֶ��� ���ȳ�ʼ��
//
//void f()
//{
//	static A aa0(0);
//	A aa1(1);//�ȹ��� ������
//	A aa2(2);//���� ������
//	static A aa4(4);//�ֲ���̬����
//}
//
////����˳��:3 0 1 2 4
////�ڶ��ι���  1 2  static�ڶ��β�������
////����˳��  ~2 ~1 ~2 ~1 ~4 ~0 ~3
//
//int main()
//{
//	f();
//	f();
//
//	return 0;
//}

//����
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
//	~A()//����
//	{
//		cout << "~A()->" << _a << endl;
//	}
//private:
//	int _a;
//};
//
//void func1(A aa)//��ֵ����
//{
//
//}
//
//void func2(A& aa)//���ô���
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


//������
void TestDate1()
{
	//����һ������
	Date d1(2022, 7, 24);
	Date d2(d1);//��������

	Date d3(201, 8, 24);
	d2 = d1 = d3;//��ֵ��������� d1.operator=(&d1, d3);
}

void TestDate2()
{
	Date d1(2022, 7, 24);
	d1 += 4;
	d1.Print();//(d1+4).Print();

	d1 += 40;//����
	d1.Print();//(d1+40).Print();

	d1 += 400;//����
	d1.Print(); //(d1 + 400).Print();

	d1 += 4000;//������
	d1.Print();//(d1+4000).Print();
}

int main()
{
	TestDate1();
	return 0;
}