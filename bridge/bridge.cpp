#include <iostream>

using namespace std;

class Implementor
{
public:
	virtual void implementation() = 0;
};


class ConcreteImplementorA : public Implementor
{
public:
	void implementation()
	{
		cout << "ConcreteImplementorA::operation" << endl;
	}
};

class ConcreteImplementorB : public Implementor
{
public:
	void implementation()
	{
		cout << "ConcreteImplementorB::operation" << endl;
	}
};



class Abstraction
{
protected:
	Implementor & implementor;
public:
	Abstraction(Implementor & impl) : implementor(impl) {}
	
	virtual void operation() 
	{
		implementor.implementation();
	}
};

class RefinedAbstraction : public Abstraction
{
public:
	RefinedAbstraction(Implementor & impl) : Abstraction(impl) 
	{}

	void operation()
	{
		implementor.implementation();
	}
};



int main()
{
	ConcreteImplementorA implA;
	ConcreteImplementorB implB;

	RefinedAbstraction rabA(implA);
	RefinedAbstraction rabB(implB);

	rabA.operation();
	rabB.operation();

	return 0;
}
