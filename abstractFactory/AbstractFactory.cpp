#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum eProductA
{
	TYPE1,
	TYPE2,
	SIZE
};


class AbstractProductA
{
public:
	virtual string method1() = 0;
};

class ProductAF1T1 : public AbstractProductA
{
public:
	string method1() { return "ProductAF1T1::method1"; }
};

class ProductAF1T2 : public AbstractProductA
{
public:
	string method1() { return "ProductAF1T2::method1"; }
};

class ProductAF2T1 : public AbstractProductA
{
public:
	string method1() { return "ProductAF2T1::method1"; }
};

class ProductAF2T2 : public AbstractProductA
{
public:
	string method1() { return "ProductAF2T2::method1"; }
};

class AbstractProductB
{
public:
	virtual string method2() = 0;
};

class ProductBF1 : public AbstractProductB
{
public:
	string method2() { return "ProductB1::method2"; }
};

class ProductBF2 : public AbstractProductB
{
public:
	string method2() { return "ProductB2::method2"; }
};

class AbstractFactory
{
public:
	virtual AbstractProductA * createProductA(eProductA type) = 0;
	virtual AbstractProductB * createProductB() = 0;
};

class ConcreteFactory1 : public AbstractFactory 
{
public:
	AbstractProductA * createProductA(eProductA type)
	{
		AbstractProductA * ret = NULL;
		switch (type)
		{
		case eProductA::TYPE1:
			ret = new ProductAF1T1;
			break;
		case eProductA::TYPE2:
			ret = new ProductAF1T2;
		default:
			break;
		}
		return ret; 
	}
	AbstractProductB * createProductB() 
	{ 
		return new ProductBF1; 
	}
};

class ConcreteFactory2 : public AbstractFactory
{
public:
	AbstractProductA * createProductA(eProductA type)
	{
		AbstractProductA * ret = NULL;
		switch (type)
		{
		case eProductA::TYPE1:
			ret = new ProductAF2T1;
			break;
		case eProductA::TYPE2:
			ret = new ProductAF2T2;
		default:
			break;
		}
		return ret;
	}
	AbstractProductB * createProductB() { return new ProductBF2; }
};

// This class shows that client code can switch easy between diffrent factories
class CtxClass 
{
	AbstractFactory *factory;
public:
	CtxClass(AbstractFactory& f) : factory(&f) {}
	void setFactory(AbstractFactory& f) { factory = &f; }

	void doSomething()
	{
		eProductA products[] = { eProductA::TYPE1, eProductA::TYPE2 };

		for (int i = 0; i < eProductA::SIZE; ++i)
		{
			AbstractProductA * productA = factory->createProductA(products[i]);
			cout << productA->method1() << endl;
			delete productA;
		}	
		
		AbstractProductB * productB = factory->createProductB();
		cout << productB->method2() << endl;
		delete productB;
	}
};


int main()
{
	ConcreteFactory1 factory1;
	ConcreteFactory2 factory2;

	CtxClass ctx(factory1);
	ctx.doSomething();

	ctx.setFactory(factory2);
	ctx.doSomething();

	return 0;
}