#include <iostream>
#include <string>
#include <map>

using namespace std;

class Prototype 
{
public:
	virtual Prototype *clone() = 0;
	virtual string getTypeName() = 0;
};

class PrototypeImpl1 : public Prototype
{
	string name;

public:

	void setName(string s) { name = s; }
	string getTypeName() { return "PrototypeImpl1"; }
	
	Prototype * clone() 
	{
		return new PrototypeImpl1(*this);
	}
};


class PrototypeImpl2 : public Prototype
{
	int value;

public:

	void setValue(int v) { value = v; }
	string getTypeName() { return "PrototypeImpl2"; }

	Prototype * clone()
	{
		return new PrototypeImpl2(*this);
	}
};

class CloneRegistry 
{
	map<string, Prototype*> _register;

public:
	void addPrototype(string key, Prototype *prototype) 
	{
		_register[key] = prototype;
	}

	Prototype * get(string lookupKey) 
	{
		return _register[lookupKey];
	}
};

int main()
{
	PrototypeImpl1 a;
	PrototypeImpl2 b;
	CloneRegistry cr;
	cr.addPrototype("key1", &a);
	cr.addPrototype("key2", &b);
	
	Prototype *p1 = cr.get("key1")->clone();
	cout << p1->getTypeName() << endl;

	Prototype *p2 = cr.get("key2")->clone();
	cout << p2->getTypeName() << endl;

	delete p1;
	delete p2;

	return 0;
}