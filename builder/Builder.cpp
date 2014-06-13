#include <iostream>
#include <string>

using namespace std;

class Product
{
	string parts;
public:
	Product() {}
	~Product(){}

	void addPart(string part) { parts += part + "\n"; }
	string getParts() { return parts; }
};

class Buider
{
public:
	virtual void buildPart1() = 0;
	virtual void buildPart2() = 0;
};

class ConcreteBuilder : public Buider
{
	Product product;

public:
	void buildPart1()
	{
		product.addPart("Builder");
	}

	void buildPart2()
	{
		product.addPart("pattern");
	}

	Product & getProduct() { return product; }
};

class Director
{
	Buider& builder;

public:
	Director(Buider & b) : builder(b) {}

	void construct()
	{
		builder.buildPart1();
		builder.buildPart2();
	}
};

int main()
{
	ConcreteBuilder builderImpl;
	Director director(builderImpl);
	director.construct();
	Product & product = builderImpl.getProduct();
	cout << product.getParts();

	return 0;
}