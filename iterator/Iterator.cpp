#include <iostream>
#include <vector>

using namespace std;

class Iterator
{
public:
	virtual void * first() = 0;
	virtual void * next() = 0;
	virtual bool isDone() = 0;
	virtual void * current() = 0;
};

class Collection
{
public:
	virtual Iterator* getIterator() = 0;
};

class ConcreteCollection : public vector<void*>, public Collection
{	
public:
	void add(void *e) { push_back(e); }
	Iterator* getIterator();
};


class ConcreteIterator : public Iterator
{
	ConcreteCollection & collection;
	size_t position;
public:
	ConcreteIterator(ConcreteCollection & col) : collection(col)
	{
		position = 0;
	}
	void * first()
	{
		position = 0;
		return collection[position];
	}
	void * next()
	{
		++position;
		if (position < collection.size())
			return collection[position];

		return NULL;
	}
	bool isDone()
	{
		if (position < collection.size())
			return false;

		return true;
	}
	void * current() { return collection[position]; }
};


Iterator* ConcreteCollection::getIterator()
{
	return new ConcreteIterator(*this);;
}

int main()
{
	int a = 1, b = 2, c = 3;

	ConcreteCollection colection;
	colection.add(&a);
	colection.add(&b);
	colection.add(&c);

	Iterator *iter = colection.getIterator();

	for (iter->first(); !iter->isDone(); iter->next())
	{
		void * pItem = iter->current();
		cout << *(static_cast<int*>(pItem)) << endl;
	}

	delete iter;

	return 0;
}