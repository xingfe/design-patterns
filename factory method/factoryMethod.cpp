#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum ProductType 
{
	PRODUCT1,
	PRODUCT2,
	SIZE
};

class Product 
{
public:
	virtual string getDescription() = 0;
};

class FM1Product1 : public Product
{
public:
	string getDescription() { return "FM1Product1"; }
};

class FM1Product2 : public Product
{
public:
	string getDescription() { return "FM1Product2"; }
};

class FM2Product1 : public Product
{
public:
	string getDescription() { return "FM2Product1"; }
};

class FM2Product2 : public Product
{
public:
	string getDescription() { return "FM2Product2"; }
};


class FactoryMethod 
{
public:
	virtual Product * createProduct(ProductType type) = 0;
};

class FactoryMethod1 : public FactoryMethod
{
public:
	Product * createProduct(ProductType type) 
	{
		Product * product = NULL;

		switch (type)
		{
			case ProductType::PRODUCT1:

				product = new FM1Product1();

				break;
			
			case ProductType::PRODUCT2:

				product = new FM1Product2();

				break;
			default:
				break;
		}

		return product;
	}
};

class FactoryMethod2 : public FactoryMethod
{
public:
	Product * createProduct(ProductType type)
	{
		Product * product = NULL;

		switch (type)
		{
		case ProductType::PRODUCT1:

			product = new FM2Product1();

			break;
		
		case ProductType::PRODUCT2:

			product = new FM2Product2();

			break;
		default:
			break;
		}

		return product;
	}
};

int main()
{
	FactoryMethod1 fm1;
	FactoryMethod2 fm2;

	vector<FactoryMethod*> v;
	v.push_back(&fm1);
	v.push_back(&fm2);

	ProductType products[] = { ProductType::PRODUCT1, ProductType::PRODUCT2 };

	vector<FactoryMethod*>::iterator it = v.begin();
	for (; it != v.end(); ++it)
	{
		for (int i = 0; i < ProductType::SIZE; ++i)
		{
			Product *p = (*it)->createProduct(products[i]);
			cout << p->getDescription() << endl;
			delete p;
		}
	}

	return 0;
}