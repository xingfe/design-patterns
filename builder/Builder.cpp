#include <iostream>
#include <string>

using namespace std;

class Product
{
	string parts;
public:
	Product() : parts("") {}
	~Product(){}

	void addPart(string part) { parts += part + "\n";  }
	string getParts() { return parts; }
};

class Buider
{
public:
	virtual void buildPart1() = 0;
	virtual void buildPart2() = 0;

	virtual Product & getProduct() = 0;
};

class BuilderSpecyficImpl : public Buider
{
	Product product;

public:
	virtual void buildPart1() 
	{
		product.addPart("Builder");
	}

	virtual void buildPart2() 
	{
		product.addPart("pattern");
	}

	Product & getProduct() { return product;  }
};

class Director 
{
	Buider& builder;

public:
	Director(Buider & b) : builder(b) {}
	
	void makeProduct()
	{
		builder.buildPart1();
		builder.buildPart2();
	}
};

int main()
{
	BuilderSpecyficImpl builderImpl;
	Buider & builder = builderImpl;
	Director director(builder);
	director.makeProduct();
	Product & product = builder.getProduct();
	cout << product.getParts();

	return 0;
}