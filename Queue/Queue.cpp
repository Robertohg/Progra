#include <iostream>
#include <set>

using namespace std;

template <class T>
class linked_list;
template <class T>
class stack;

template <class T>
class nodee
{
private:
	T dato;
	nodee<T>* p_next;
public:
	nodee(const T& d, nodee<T>* n = nullptr) :
		dato(d), p_next(n) {}

	~nodee() = default;

	friend class linked_list<T>;
	friend class stack<T>;
};


template <class T>
class linked_list
{
private:
	nodee<T>* p_head;
public:
	class iterator
	{
	private:
		nodee<T>* p_current;

	public:
		void del() { ~linked_list(); }
		iterator(nodee<T>* n = nullptr) : p_current(n) {}
		~iterator() = default;

		iterator& operator ++ ()
		{
			p_current = p_current->p_next;
			return *this;
		}

		T& operator * ()
		{
			return p_current->dato;
		}

		bool operator != (const iterator& it)
		{
			return p_current != it.p_current;
		}

	};

	linked_list() : p_head(nullptr) {}


	~linked_list()
	{

		while (p_head != nullptr)
			pop_front();
		delete p_head;

	}


	void pop_front()
	{
		if (!p_head) {
			return;
		}
		nodee<T>* temp = p_head;
		p_head = p_head->p_next;
		delete temp;
	}
	void pop_back()
	{
		nodee<T>* temp = p_head;
		nodee<T>* last_ptr = nullptr;
		while (temp->p_next != nullptr)
		{
			last_ptr = temp;
			temp = temp->p_next;
		}

		last_ptr->p_next = nullptr;
		delete temp;

		last_ptr = nullptr;
		delete last_ptr;
	}
	void reverse()
	{
		nodee<T>* prev = nullptr, * current = nullptr, * next = nullptr;
		current = p_head;
		while (current != nullptr)
		{
			next = current->p_next;
			current->p_next = prev;
			prev = current;
			current = next;
		}
		p_head = prev;
		prev = nullptr;
		delete prev;
		delete current;
		delete next;
	}
	void insert_front(const T& d)
	{
		p_head = new nodee<T>(d, p_head);
	}

	void insert_back(const T& d)
	{
		nodee<T>** p_last = &p_head;
		while (*p_last)
			p_last = &(*p_last)->p_next;

		*p_last = new nodee<T>(d);

	}

	const iterator begin()
	{
		return { p_head };
	}

	const iterator end()
	{
		return { nullptr };
	}
	friend class stack<T>;
};

template <class T>
class stack : public linked_list<T> {
public:
	stack() : p_head(nullptr) {}
	nodee<T>* p_head;
	class iterator
	{
	private:
		nodee<T>* p_current;

	public:
		void del() { ~stack(); }
		iterator(nodee<T>* n = nullptr) : p_current(n) {}
		~iterator() = default;

		iterator& operator ++ ()
		{
			p_current = p_current->p_next;
			return *this;
		}

		T& operator * ()
		{
			return p_current->dato;
		}

		bool operator != (const iterator& it)
		{
			return p_current != it.p_current;
		}

	};
	~stack()
	{
		while (p_head != nullptr)
			pop();
		delete p_head;
	}
	void pop()
	{
		nodee<T>* temp = this->p_head;
		nodee<T>* last_ptr = nullptr;
		while (temp->p_next != nullptr)
		{
			last_ptr = temp;
			temp = temp->p_next;
		}

		last_ptr->p_next = nullptr;

		delete temp;

		last_ptr = nullptr;
		delete last_ptr;
	}

	void push(const T& d)
	{
		nodee<T>** p_last = &p_head;
		while (*p_last)
			p_last = &(*p_last)->p_next;

		*p_last = new nodee<T>(d);

	}
	const iterator begin()
	{
		return { p_head };
	}

	const iterator end()
	{
		return { nullptr };
	}
};




int main()
{

	stack<int> stack;
	stack.insert_back(10);
	stack.insert_back(8);
	stack.pop_back();


	for (int e : stack)
		cout << e << " ";
	cout << endl;



}