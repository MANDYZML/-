#pragma once

//���������ռ�
namespace bit
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const _iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		//const ������
		const iterator begin() const
		{
			return _str;
		}

		const iterator end() const
		{
			return _str + _size;
		}

		//ȫȱʡ 
		//string(const char* str = "\0")
		//string(const char* str = "")//������\0
		//	:_str(new char[strlen(str)+1 ])
		//	,_size(strlen(str))
		//	,_capacity(strlen(str))
		//{
		//	strcpy(_str, str);
		//}
		//�ṩ�޲ε�
		string()
			:_str(new char[1])
			, _size(0)
			, _capacity(0)
		{
			//�ն�������Ҳ��\0
			_str[0] = '\0';
		}

		

		//������ô��ʼ���ն���
		/*string()
			:_str(new char[1])
			, _size(0)
			, _capacity(0)*/


		//{
		//	//�ն�������Ҳ��\0
		//	_str[0] = '\0';
		//}

		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];

			strcpy(_str, str);
		}

		//�������� s2(s1)
		//string(const string& s)
		//	:_str(new char[s._capacity+1])//+1�Ǹ�\0 ���ռ�
		//	,_size(s._size)
		//	,_capacity(s._capacity)
		//{
		//	//��������
		//	strcpy(_str, s._str);
		//}

		//�Լ�дһ����ֵ s1 = s3
		//string& operator = (const string& s)//s �� s3
		//{
		//	//�Է��Լ����Լ���ֵ
		//	if (this != &s)
		//	{
		//		char* tmp = new char[s._capacity + 1];
		//		strcpy(tmp, s._str);//�������� s3�������ݵ��¿ռ� s1

		//		delete[] _str;//�ͷ�s1ԭ���ռ�

		//		_str = tmp;//s1ָ���¿ռ� ��s3һ����
		//		_size = s._size;
		//		_capacity = s._capacity;
		//	}

		//	return *this;
		//}


		//�ִ�д��
		void swap(string& tmp)
		{
			::swap(_str, tmp._str);
			::swap(_size, tmp._size);
			::swap(_capacity, tmp._capacity);
		}
		string(const string& s)
			:_str(nullptr)
			,_size(0)
			,_capacity(0)
			//s2(s1)
		{
			string tmp(s._str);
			swap(tmp);//this->swap(tmp);
		}

		 
		//�ִ�д��
		//s1 = s3
		string& operator = (const string& s)//s �� s3
		{
			//�Է��Լ����Լ���ֵ
			if (this != &s)
			{
				string tmp(s._str);
				string tmp(s);

				swap(tmp); //s1 �� tmp
			}

			return *this;
		}




		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		const char* c_str() const
		{
			return _str;
		}

		size_t size() const
		{
			return _size;
		}

		size_t capacity() const
		{
			return _capacity;
		}


		const char& operator[](size_t pos) const
		{
			assert(pos < _size);

			return _str[pos];
		}
		 
		char& operator[](size_t pos)
		{
			assert(pos < _size);

			return _str[pos];
		}

		//����
		void reserve(size_t n)
		{
			if (n > _capacity)//��capcity�� ������
			{
				char* tmp = new char[n+1];//��n+1�����¿ռ�
				strcpy(tmp, _str);
				delete[] _str;

				_str = tmp;
				_capacity = n;
			}
		}

		//���ռ�+��ʼ��
		void resize(size_t n, char ch = '\0')
		{
			if (n > _size)
			{
				//��������
				reserve(n);
				for (size_t i = _size; i < n; ++i)
				{
					_str[i] = ch;
				}
				_str[n] = '\0';
				_size = n;
			}
			else // <=
			{
				//ɾ������
				_str[n] = '\0';//���ֱ�Ӹ�\0
				_size = n;
			}

		}

		//β��
		void push_back(char ch)
		{
			//������˾�����
			//if (_size == _capacity)
			//{
			//	reserve(_capacity == 0 ? 4 : _capacity * 2);
			//}
			//_str[_size] = ch;//��ֵ�Ž�size
			//++_size;
			//_str[_size] = '\0';

			insert(_size, ch); 

		}

		//��һ���ַ���
		void append(const char* str)
		{
			//������봮�ĳ���
			//size_t len = strlen(str);
			//if (_size + len > _capacity)
			//{
			//	reserve(_size + len);
			//}
			//strcpy(_str + _size, str);//��size��ʼ���󿽱�
			//// strcat(_str, str);
			//_size += len;
			insert(_size, str);

		}


		string& operator +=(char ch)
		{
			push_back(ch);
			return *this;
		}

		//���ַ���
		string& operator +=(const char* str)
		{
			append(str);
			return *this;
		}

		//��ĳ��λ�ò����ַ�
		string& insert(size_t pos, char ch)
		{
			assert(pos < _size);
			 
			//���˾�����
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}

			//Ų������
			/*int end = _size;
			while (end >= (int)pos)
			{
				_str[end + 1] = _str[end];
				--end;
			}*/

			size_t end = _size + 1;
			while (end >= pos)
			{
				_str[end - 1] = _str[end];
				--end;
			}

			_str[pos] = ch;
			++_size;

			return *this;
		}

		string& insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			//Ų������ �ѿռ�ճ���
			size_t end = _size + len;//Ųһ�����ַ���
			while (end >= pos + len - 1)
			{
				_str[end] = _str[end - len];
				--end;
			}

			strncpy(_str + pos, str, len);
			_size += len;

			return *this;
		}

		//��posλ��ɾ��length���ַ�
		void erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);

			if (len == npos || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
		}

		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}

		//��posλ�� ��һ���ַ�
		size_t find(char ch, size_t pos = 0) const
		{
			assert(pos < _size);
			for (size_t i = pos; i < _size; i++)
			{
				if (ch == _str[i])//����ҵ���
				{
					return i;//�������λ�õ��±�
				}
			}
			//û���ҵ�
			return npos;
		}

		//��һ��
		size_t find(const char* sub, size_t pos = 0) const
		{
			assert(sub);
			assert(pos < _size);
			const char* ptr = strstr(_str + pos, sub);
			if (ptr == nullptr)//û�ҵ�����ִ�
			{
				//���ؿ�ָ��
				return npos;
			}
			else //���ǿ�ָ��
			{
				return ptr - _str;//strstr ָ���λ�� - ��ʼλ��
			}
		}

		string sbustr(size_t pos, size_t len = npos) const
		{
			assert(pos < _size);
			size_t reallen = len;
			if (len == npos || pos+len > _size)//�ж���ȡ����
			{
				reallen = _size - pos;
			}

			string sub;
			for (size_t i = 0; i < reallen; ++i)
			{
				sub += _str[pos + i];//��ʵ�ʳ�������ȡ��
			}
			return sub;
		}
		
		//�ַ����Ƚϴ�С
		bool operator > (const string& s) const
		{
			return strcmp(_str, s._str) > 0;//>0 ������
		}
		bool operator == (const string& s) const
		{
			return strcmp(_str, s._str) == 0;
		}
		bool operator >= (const string& s) const
		{
			return *this > s || *this == s;
		}
		bool operator <= (const string& s) const
		{
			return !(*this > s);
		}
		bool operator < (const string& s) const
		{
			return !(*this >= s);
		}
		bool operator != (const string& s) const
		{
			return !(*this == s);
		}
		


	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		//��̬��Ա���� ����
		//static size_t npos;
		//c++���� const static�﷨���⴦��
		//ֱ�ӿ��Ե��� �����ʼ��
	public:
		const static size_t npos = -1;//����Ҫ�����涨��
	};

	//����
	//size_t string :: npos = -1;

	//������
	ostream& operator << (ostream& out, const string& s)
	{
		//��ÿ���ַ������
		for (size_t i = 0; i < s.size(); ++i)
		{
			out << s[i];
		}

		return out;
	}

	//����ȡ
	//istream& operator >> (istream& in, string& s)
	//{
	//	char ch;
	//	//in >> ch;
	//	ch = in.get();//��ȡÿһ���ַ�
	//	s.reserve(128);//���ݴ����ͼ�����
	//	while (ch != ' ' || ch != '\n')
	//	{
	//		size_t old = s.capacity();
	//		s += ch;
	//		
	//		if (s.capacity() != old)//˵��������
	//		{
	//			cout << old << "����" << s.capacity() << endl;
	//		}
	//		in >> ch;
	//	}

	//	return in;
	//}

	istream& operator >> (istream& in, string& s)
	{

		s.clear();//��������
		char ch;
		ch = in.get();//��ȡÿһ���ַ�
		const size_t N = 32;
		char buff[N];
		size_t i = 0;

		while (ch != ' ' || ch != '\n')
		{
			buff[i++] = ch;//��buff�����
			if (i == N - 1)//˵������ ��һ��λ����\0��
			{
				buff[i] = '\0';
				s += buff;
				i = 0;
			}

			ch = in.get();

		}
		buff[i] = '\0';
		s += buff;

		return in;
	}

	void test_string1()
	{
		std :: string s1("hello world");
		std :: string s2;

		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
		 
		for (size_t i = 0; i < s1.size(); ++i)
		{
			cout << s1[i] <<" ";
		}
		cout << endl;

		for (size_t i = 0; i < s1.size(); ++i)
		{
			s1[i]++; 
		}

		for (size_t i = 0; i < s1.size(); ++i)
		{
			s1[i]++;
		}
		cout << endl;
	}

	void test_string2()
	{
	    string s1("hello world");
		//������
		string::iterator it = s1.begin();
		while (it != s1.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		it = s1.begin();
		while (it != s1.end())
		{
			*it += 1;
			++it;
		}
		cout << endl;

		for (auto ch : s1)
		{
			cout << ch << " ";
		}
		cout << endl;
	}

	//�������� -- ��ǳ����

	void test_string3()
	{
		//ǳ���� 
		//������� ָ��ͬһ�ռ� ����������������
		string s1("hello world");
		string s2(s1);
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		//��� --����

		s2[0] = 'x';
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl; //�޸�����һ�� ����û��Ӱ��
	
		string s3("111111111111111111111111");
		s1 = s3;
		cout << s1.c_str() << endl;
		cout << s3.c_str() << endl;

	}

	void test_string4()
	{
		string s1("hello world");
		string s2("xxxxxxxxxxxxxxxx");

		s1.swap(s2);
		swap(s1, s2);
	}

	void test_string5()
	{
		string s1("hello world");
		cout << s1.c_str() << endl;
		s1.push_back('x');
		cout << s1.c_str() << endl;

		s1 += 'x';
		s1 += 'y';
		s1 += 'z';
		cout << s1.c_str() << endl;
	}

	void test_string6()
	{
		string s1("hello world");
		cout << s1.c_str() << endl;

		s1 += ' ';
		s1.append("world");
		cout << s1.c_str() << endl;

		s1 += "bit hello";

		s1.insert(5, '#');//������λ�ò���#
		cout << s1.c_str() << endl;

		s1.insert(0, '#');
		cout << s1.c_str() << endl;
	}

	void test_string7()
	{
		string s1("hello world");
		cout << s1.c_str() << endl;

		s1.insert(2, "world");
		cout << s1.c_str() << endl;

		s1.insert(0, "world ");
		cout << s1.c_str() << endl;
	}

	void test_string8()
	{
		string s1("hello world");
		s1.erase(1, 10);
		cout << s1.c_str() << endl;

		//ɾ�ܶ�
		string s2("hello world");
		s2.erase(1);
		cout << s2.c_str() << endl;

		//ɾ����
		string s3("hello world");
		s3.erase(1, 2);
		cout << s3.c_str() << endl;
	}

	void test_string9()
	{
		/*string s1;
		cin >> s1;
		cout << s1 << endl;*/

		string s1("hello");
		cout << s1 << endl;
		cout << s1.c_str() << endl;

		s1 += '\0';
		s1 += "world";
		cout << s1 << endl;
		cout << s1.c_str() << endl;


		string s3, s4;
		cin >> s3 >> s4;
		cout << s3 << s4 << endl;
	}



}