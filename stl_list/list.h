#pragma once
namespace bit
{
	template<class T>
	class list_node
	{
		T _data;
		list_node<T>* _next;
		list_node<T>* _prev;

		list_node(const T& x = T())
			:_data(x)
			,_next(nullptr)
			,_prev(nullptr)
		{}
	};

	template<class T>
	struct __list_iteator
	{
		typedef list_node<T> Node;
		typedef __list_iteator<T> iterator;
		Node* _node;

		__list_iteator(Node* node)
			:_node(node)
		{}

		bool operator!=(const iterator& it) const
		{
			return _node != it._node;
		}

		T& operator* ()
		{
			return _node->_data;
		}

		//++it
		iterator& operator++()
		{
			_node = _node->_next;
			return *this; 
		}

		//ºóÖÃ++  it++
		iterator& operator++(int)
		{
			iterator tmp(*this);
			_node = _node->_next;
			return tmp;
		}


		//--it
		iterator& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		//it--
		iterator& operator--(int)
		{
			iterator tmp(*this);
			_node = _node->_prev;
			return tmp;
		}
	};



	template<class T>
	class list
	{
		typedef list_node<T> node;
	public:
		typedef __list_iteator<T> iterator;
		
		iterator begin()
		{
			return iterator(_head->_next); 
		}

		iterator end()
		{
			return iterator(_head);
		}


		list()
		{
			_head = new Node;
			_head->next = _head;
			_head->prev = _head;
		 }

		void push_back(const T& x)
		{
			Node* tail = _head->_prev;
			Node* newnode = new Node(x);

			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
		}

	private:
		Node* _head;
	};

	void test_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4); 
		lt.push_back(5); 

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;


		 it = lt.begin();
		while (it != lt.end())
		{
			*it *= 2;
			++it;
		}
		cout << endl;

		for (auto e : lt)
		{
			cout << e << " "; 
		}
		cout << endl;
	}
}