#pragma once
#include<assert.h>
namespace zml
{
	template<class T>
	class vector
	{
		
	public:
		typedef T* iterator;
		typedef const * const_iterator;


		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			_finish;
		}


		const_iterator begin() const
		{
			return _start;
		}
		const_iterator end() const
		{
			_finish;
		}




		  vector()//���캯��
			  :_start(nullptr)
			  ,_finish(nullptr)
			  ,_end_of_storage(nullptr)
		  {}

		  ~vector()
		  {
			  delete[] _start;
			  _start = _finish = _end_of_storage = nullptr;
		  }

		  size_t capacity() const
		  {
			  return _end_of_storage - _start;
		  }
		
		  const T& operator[](size_t pos) const
		  {
			  assert(pos < size());
			   
			  return _start[pos];
		  }


		  size_t size() const
		  {
			  return _finish - _start;
		  }

		  void reserve(size_t n)
		  {
			  if (n > capacity())//����
			  {
				  size_t sz = size();
				  T* tmp = new T[n];
				  if (_start)//�ɿռ䲻�ǿ�
				  {
					  memcpy(tmp, _start, sizeof(T) * sz);//�������¿ռ���
					  delete[] _start;//�ͷžɿռ�
				  }
				 
				  _start = tmp;
				  _finish = tmp +sz;
				  _end_of_storage = _start + n;
			  }
		  }


		  void push_back(const T& x)
		  {
			/*  if (_finish == _end_of_storage)
			  {
				  reserve(capacity() == 0 ? 4 : capacity() * 2);
			
			  }

			  *_finish = x;
			  ++_finish;*/

			  insert(end(), x);
		  }

		  //������ʧЧ����
		  

		  void resize(size_t n, const T& val=T())
		  {
			  if (n > capacity())
			  {
				  reserve(n);//����
			  }
			  if(n > size())
			  {
				  //��ʼ����ֵ
				  while (_finish < _start + n)
				  {
					  *_finsih = val;
					  ++_finish;
				  }
			  }

			  else //<= size
			  {
				  _finish = _start + n;
			  }
		  }
		  
		  //βɾ
		  void pop_back()
		  {
			  assert(_finish > _start);
			  --_finish;
		  }

		  //������
		  iterator insert(iterator pos, const T& x)
		  {
			  assert(pos >= _start);
			  assert(pos <= _finish);

			  if (_finish == _end_of_storage)
			  {
				  size_t len = pos - _start;
				  reserve(capacity() == 0 ? 4 : capacity() * 2);
				  pos = _start + len;
			  }
			  //Ų������
			  iterator end = _finish - 1;
			  while (end >= pos)
			  {
				  *(end + 1) = *end;
				  --end;
			  }
			  *pos = x;
			  ++_finish; 

			  return pos;
		  }

		  //ɾ����
		  iterator erase(iterator pos)
		  {
			  assert(pos >= _start);
			  assert(pos <= _finish);

			  iterator begin = pos + 1;
			  while (begin < _finish)
			  {
				  *(begin - 1) = *begin;
				  ++begin;
			  }
			  --_finish;

			  //if (size() < capacity() / 2)
			  //{
			  ////����--��ʱ�任�ռ�

			  //}

			  return pos;
		  }

	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};

	void  Func(const vector<int>& v)
	{
		vector<int>::const_iterator it = v.begin();
		while (it != v.end())
		{
			//*it = 10; //�����޸�
			cout << *it << " ";
			++it;
		}
		cout << endl; 

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector1()
	{
		/*double d = 2.2 ;
		const int& i = d;

		vector<string> v;
		v.push_back("xxxxxxxx");*/

		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);

		for (size_t i = 0; i < v.size(); ++i)
		{
			cout << v[i] << " ";
		}
		cout << endl;

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;  

		v.pop_back();
		v.pop_back();
		v.pop_back();


		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	void test_vector2()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
	

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		auto p = find(v.begin(), v.end(), 3);
		if (p != v.end())//�ҵ���
		{
			v.insert(p, 30);
		}



		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector3()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		auto p = find(v.begin(), v.end(), 3);
		if (p != v.end())//�ҵ���
		{
			v.erase(p);
		}

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		v.erase(v.begin());

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector4()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		//Ҫ��ɾ�����е�ż��
		auto it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)//��ż��
			{
				v.erase(it);//��ż����ɾ 
			}
			else
			{
				++it;
			}
			
		}

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector5()
	{
		std::vector<int> v;
		v.reserve(10);  
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		

		//�����е�ż��ǰ�����һ��ż��2��
		auto it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)//��ż��
			{
				it = v.insert(it, *it * 2);//��ԭʼָ��*2 ����
				++it;//�����²����ֵ
				++it; //�����Ѿ��жϹ���ֵ
			}
			else
			{
				++it;//����ż����++
			}
		 
		}

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector6()
	{
		vector<int> v1;
		v1.resize(10, 0);
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<int> v2;
		v2.resize(10);
		v2.push_back(1);
		v2.push_back(2);
		v2.push_back(3);
		v2.push_back(4);
		v2.push_back(5);

		v2.resize(8,8);
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;

		v2.resize(20, 20);
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;

		v2.resize(3);
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;
}