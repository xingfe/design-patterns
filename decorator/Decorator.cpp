#include <iostream>
#include <string>

using namespace std;

class Component
{
public:
	virtual string method() = 0;
};

class ConcreteComponent : public Component
{
	string method() { return "pattern"; }
};

class Decorator : public Component
{
	Component & component;

public:
	Decorator(Component & c) : component(c) { }
	string method() { return "Decorator " + component.method(); }
};


int main()
{
	ConcreteComponent comp1;
	Decorator dec1(comp1);
	Decorator dec2(static_cast<Component&>(dec1));

	cout << dec1.method() << endl;
	cout << dec2.method() << endl;

	return 0;
}