#define _CRT_SECURE_NO_WARNINGS 1

//����c����
#include<stdio.h>
#include<stdlib.h> //rand�ᱨ��--������ͻ  �������������

//int main()
//{
//	printf("hello world\n");
//	return 0;
//}

//c++д
//#include<iostream>
//using namespace std;//std��c++��׼��������ռ�
//����ȫ��ȥ�ң����û�л�����չ����std����ȥ��
//
//int main()
//{
//	std::cout << "hello world" std::<<endL;
//}

//�����ռ��� --namespace
//namespace  bit //����һ���ռ��bit
//{
//	int rand = 0;//��������ռ��ȫ�ֱ���
//}
//
//int main()
//{
//	printf("%d\n", rand);//����Ƿ���ȫ��rand--Ҳ���ǿ����  
//	printf("%d\n", bit::rand);//ָ�����������ռ�
//
//	return 0;
//}

//��
//int a = 0;//ȫ��
//int main()
//{
//	int a = 1;//�ֲ�
//	printf("%d\n", a);//�ͽ�ԭ�� ���Ҿֲ�  ��ӡ1
//	                   //�ֲ�û����ȫ��
//
//	//:: �������޶���
//	printf("%d\n", ::a);//ȥ:: �����ȥ�� �հ׾��� ȫ����
//	return 0;
//}


//�����ռ仹�ܶ��庯��
//namespace sql //�����ռ仹��Ƕ��
//{
//	int a = 0;
//
//	namespace  bit //����һ���ռ��bit
//	{
//		int rand = 0;//��������ռ��ȫ�ֱ���
//		void func()
//		{
//			printf("func()\n");//���庯��
//		}
//		struct TreeNode //��������
//		{
//			struct TreeNode* left;
//			struct TreeNode* right;
//			int val;
//		};
//	}
//}
//int main()
//{
//	printf("%d\n", rand);//����Ƿ���ȫ��rand--Ҳ���ǿ����  
//	printf("%d\n", sql::bit::rand);//ָ�����������ռ�
//	
//	sql::bit::func();
//	struct sql::bit::TreeNode node;//��ָ���ռ���
//	return 0;
//}

#include<iostream> //io��
//using namespace std;//std��c++��׼��������ռ�
//����ȫ��ȥ�ң����û�л�����չ����std����ȥ��

//չ�����õ�
//using std::cout;
//using std::cin;
//
//int main()
//{
//	// << ������
//	std::cout << "hello world" std::<<endL;//�ȼ��ڻ���
//	std::cout << "hello world" std::<<"\n ";
//
//	//�Զ�ʶ������
//	int i = 11;
//	double d = 11.11;
//	printf("%d,%f", i, d);//c����
//	std::cout << i << d << std::endL;//����Ҫָ������
//
//	//����Ҳ��  >> ����ȡ
//	scanf("%d%lf", &i, &d);
//	std::cin >> i >> d;
//}   



//��Ͷ���
#include<iostream> 
using namespace std;

//���������
//class Person
//{
//public:
//	void PrintPersonInfo();
//private:
//	char _name[2];
//	char _gender[3];
//	int _age;
//}; //{} �������Ķ���һ����
//
////���� PrintPesonInfo ������Person �����ľֲ���
////�������ⶨ���Աʱ ��Ҫʹ�� :: �����������ָ����Ա�����ĸ�����
//void Person::PrintPersonInfo()
//{
//	cout << _name << " " << _gender << " " << _age < endl;
//}
//
////���ʵ����
//class Person
//{
//public:
//	void PrintPersonInfo(); //��������
//private:
//	char _name[2];        //����
//	char _gender[3];
//	int _age;
//}; 
//void Person::PrintPersonInfo()  //����
//{
//	cout << _name << " " << _gender << " " << _age < endl;
//}

//thisָ��

//���ʺ͵���֮������ĸ��д���  --�շ巨 GetYear
//����ȫ��Сд ����֮���� _ �ָ�  get_year
//class Date
//{
//public:
//	void Init(int year, int month, int day)
//   //void Init(Date* const this, int year, int month, int day)
//		//const���ε��� thisָ�뱾�� ���ܱ��޸�
//		//ָ������ݿ��Ա��޸�
//	{
//		//��ʼ��
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
//	int _year;   //���� 
//	int _month;
//	int _day;
//
//};
//
////ʵ�κ��β�λ�ò�����ʾ���ݺͽ���thisָ��
////���ǿ����ڳ�Ա�������ڲ�ʹ��thisָ��
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

//���캯��
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
