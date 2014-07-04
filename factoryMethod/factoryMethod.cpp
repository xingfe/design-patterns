#include <iostream>
#include <string>

using namespace std;

enum eProduct
{
	PRODUCT1,
	PRODUCT2,
	SIZE
};

class Product
{
public:
	virtual string method() = 0;
};

class Product1 : public Product
{
public:
	string method() { return "Product1::method"; }
};

class Product2 : public Product
{
public:
	string method() { return "Product2::method"; }
};

class Creator 
{
protected:
	virtual Product * factoryMethod(eProduct type) = 0;
public:
	void anOperation() 
	{
		eProduct products[] = { PRODUCT1, PRODUCT2 };

		for (int i = 0; i < eProduct::SIZE; ++i)
		{
			Product * p = factoryMethod(products[i]);
			cout << p->method() << endl;
			delete p;
		}
	}
};

class ConcreteCreator : public Creator
{
protected:
	Product * factoryMethod(eProduct type)
	{
		Product * ret = NULL;
		switch (type)
		{
		case eProduct::PRODUCT1:
			ret = new Product1;
			break;
		case eProduct::PRODUCT2:
			ret = new Product2;
			break;
		default:

			break;
		}
		return ret;
	}
};

int main()
{
	ConcreteCreator cr;
	cr.anOperation();

	return 0;
}