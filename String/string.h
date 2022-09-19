#pragma once

//定义命名空间
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

		//const 迭代器
		const iterator begin() const
		{
			return _str;
		}

		const iterator end() const
		{
			return _str + _size;
		}

		//全缺省 
		//string(const char* str = "\0")
		//string(const char* str = "")//隐含有\0
		//	:_str(new char[strlen(str)+1 ])
		//	,_size(strlen(str))
		//	,_capacity(strlen(str))
		//{
		//	strcpy(_str, str);
		//}
		//提供无参的
		string()
			:_str(new char[1])
			, _size(0)
			, _capacity(0)
		{
			//空对象里面也有\0
			_str[0] = '\0';
		}

		

		//不能这么初始化空对象
		/*string()
			:_str(new char[1])
			, _size(0)
			, _capacity(0)*/


		//{
		//	//空对象里面也有\0
		//	_str[0] = '\0';
		//}

		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];

			strcpy(_str, str);
		}

		//拷贝构造 s2(s1)
		//string(const string& s)
		//	:_str(new char[s._capacity+1])//+1是给\0 开空间
		//	,_size(s._size)
		//	,_capacity(s._capacity)
		//{
		//	//拷贝数据
		//	strcpy(_str, s._str);
		//}

		//自己写一个赋值 s1 = s3
		//string& operator = (const string& s)//s 是 s3
		//{
		//	//以防自己给自己赋值
		//	if (this != &s)
		//	{
		//		char* tmp = new char[s._capacity + 1];
		//		strcpy(tmp, s._str);//拷贝数据 s3拷贝数据到新空间 s1

		//		delete[] _str;//释放s1原来空间

		//		_str = tmp;//s1指向新空间 和s3一样大
		//		_size = s._size;
		//		_capacity = s._capacity;
		//	}

		//	return *this;
		//}


		//现代写法
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

		 
		//现代写法
		//s1 = s3
		string& operator = (const string& s)//s 是 s3
		{
			//以防自己给自己赋值
			if (this != &s)
			{
				string tmp(s._str);
				string tmp(s);

				swap(tmp); //s1 和 tmp
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

		//扩容
		void reserve(size_t n)
		{
			if (n > _capacity)//比capcity大 才扩容
			{
				char* tmp = new char[n+1];//开n+1个的新空间
				strcpy(tmp, _str);
				delete[] _str;

				_str = tmp;
				_capacity = n;
			}
		}

		//开空间+初始化
		void resize(size_t n, char ch = '\0')
		{
			if (n > _size)
			{
				//插入数据
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
				//删除数据
				_str[n] = '\0';//最后直接给\0
				_size = n;
			}

		}

		//尾插
		void push_back(char ch)
		{
			//如果满了就扩容
			//if (_size == _capacity)
			//{
			//	reserve(_capacity == 0 ? 4 : _capacity * 2);
			//}
			//_str[_size] = ch;//把值放进size
			//++_size;
			//_str[_size] = '\0';

			insert(_size, ch); 

		}

		//加一个字符串
		void append(const char* str)
		{
			//计算插入串的长度
			//size_t len = strlen(str);
			//if (_size + len > _capacity)
			//{
			//	reserve(_size + len);
			//}
			//strcpy(_str + _size, str);//从size开始往后拷贝
			//// strcat(_str, str);
			//_size += len;
			insert(_size, str);

		}


		string& operator +=(char ch)
		{
			push_back(ch);
			return *this;
		}

		//加字符串
		string& operator +=(const char* str)
		{
			append(str);
			return *this;
		}

		//在某个位置插入字符
		string& insert(size_t pos, char ch)
		{
			assert(pos < _size);
			 
			//满了就扩容
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}

			//挪动数据
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
			//挪动数据 把空间空出来
			size_t end = _size + len;//挪一整个字符串
			while (end >= pos + len - 1)
			{
				_str[end] = _str[end - len];
				--end;
			}

			strncpy(_str + pos, str, len);
			_size += len;

			return *this;
		}

		//在pos位置删除length个字符
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

		//从pos位置 找一个字符
		size_t find(char ch, size_t pos = 0) const
		{
			assert(pos < _size);
			for (size_t i = pos; i < _size; i++)
			{
				if (ch == _str[i])//如果找到了
				{
					return i;//返回这个位置的下标
				}
			}
			//没有找到
			return npos;
		}

		//找一串
		size_t find(const char* sub, size_t pos = 0) const
		{
			assert(sub);
			assert(pos < _size);
			const char* ptr = strstr(_str + pos, sub);
			if (ptr == nullptr)//没找到这个字串
			{
				//返回空指针
				return npos;
			}
			else //不是空指针
			{
				return ptr - _str;//strstr 指向的位置 - 起始位置
			}
		}

		string sbustr(size_t pos, size_t len = npos) const
		{
			assert(pos < _size);
			size_t reallen = len;
			if (len == npos || pos+len > _size)//有多少取多少
			{
				reallen = _size - pos;
			}

			string sub;
			for (size_t i = 0; i < reallen; ++i)
			{
				sub += _str[pos + i];//把实际长度依次取完
			}
			return sub;
		}
		
		//字符串比较大小
		bool operator > (const string& s) const
		{
			return strcmp(_str, s._str) > 0;//>0 就是真
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

		//静态成员变量 声明
		//static size_t npos;
		//c++特例 const static语法特殊处理
		//直接可以当作 定义初始化
	public:
		const static size_t npos = -1;//不需要类外面定义
	};

	//定义
	//size_t string :: npos = -1;

	//流插入
	ostream& operator << (ostream& out, const string& s)
	{
		//把每个字符都输出
		for (size_t i = 0; i < s.size(); ++i)
		{
			out << s[i];
		}

		return out;
	}

	//流提取
	//istream& operator >> (istream& in, string& s)
	//{
	//	char ch;
	//	//in >> ch;
	//	ch = in.get();//获取每一个字符
	//	s.reserve(128);//扩容次数就减少了
	//	while (ch != ' ' || ch != '\n')
	//	{
	//		size_t old = s.capacity();
	//		s += ch;
	//		
	//		if (s.capacity() != old)//说明扩容了
	//		{
	//			cout << old << "扩容" << s.capacity() << endl;
	//		}
	//		in >> ch;
	//	}

	//	return in;
	//}

	istream& operator >> (istream& in, string& s)
	{

		s.clear();//清理数据
		char ch;
		ch = in.get();//获取每一个字符
		const size_t N = 32;
		char buff[N];
		size_t i = 0;

		while (ch != ' ' || ch != '\n')
		{
			buff[i++] = ch;//往buff里面放
			if (i == N - 1)//说明满了 有一个位置是\0的
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
		//迭代器
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

	//拷贝构造 -- 深浅拷贝

	void test_string3()
	{
		//浅拷贝 
		//程序崩溃 指向同一空间 析构不能析构两次
		string s1("hello world");
		string s2(s1);
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		//深拷贝 --上面

		s2[0] = 'x';
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl; //修改其中一个 互相没有影响
	
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

		s1.insert(5, '#');//第六个位置插入#
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

		//删很多
		string s2("hello world");
		s2.erase(1);
		cout << s2.c_str() << endl;

		//删几个
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