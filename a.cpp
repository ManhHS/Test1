#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

template <class T>
struct L1Item{
	L1Item(): pNext(NULL) {}
	L1Item(T& a): data(a), pNext(NULL){}
	private: 
		T data;
		L1Item<T>* pNext;
};

template<class T>
class MyClass
{
	L1Item<T>* pHead;
	size_t _size;
	public:
	MyClass(): pHead(NULL),_size(0){}
	~MyClass()
	{
		this->clean();
	}
	
	void clean()
	{
		if(pHead != NULL)
		{
			delete pHead;
			pHead = NULL;
			_size = 0;
		}
	}
	bool isEmpty()
	{
		return pHead == NULL;
	}
	size_t getSize()
	{
		return this->_size;
	}
	
	template<class T>
	T& at(int i)
	{
		int element = -1;
		if(this->pHead != NULL)
		{
			if(i>=0)
			{
				L1Item<T> *p = this->pHead;
				for(p;p=p->pNext)
				{
					b++;
					if(b==i)
						return *p;
				}
			}	
		}
		return NULL;
	}
	
	template<class T>
	T& operator[](int i)
	{
		int element = -1;
		if(this->pHead != NULL)
		{
			if(i >= 0)
			{
				L1Item<T> *p = this->pHead;
				for(p;p=p->next)
				{
					if(element == i)
						return *p;
				}
			}
		}
	}
	
	template<class T>
	int append(T& a)
	{
		L1Item<T> *r = new L1Item<T>();
		r->data = a;
		r->pNext = NULL;
		if(this->pHead == NULL)
		{
			pHead = r;
		}
		else{
			L1Item<T> *p = this->pHead;
			for(p;p->pNext)
			{
				if(p->pNext == NULL)
				{
					p->pNext = r;					
				}
			}			
		}
	}
	
	template<class T>
	int prepend(T& a)
	{
		L1Item<T> *r = new L1Item<T>();
		r->data = a;
		r->pNext = NULL;
		if(pHead == NULL)
		{
			pHead = r;
		}
		else{
			r->pNext = pHead;
			pHead = r;
		}
	}
	
};

int main()
{
	return 0;
}