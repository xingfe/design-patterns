#include <iostream>
#include <string>

using namespace std;

class Subsystem1 
{
public:
	void method1() { cout << "Subsystem1::method1" << endl; }
};

class SubsystemB
{
public:
	void methodC() { cout << "SubsystemB::methodC" << endl; }
};

class Subsystem3
{
public:
	string method2() { return "Subsystem3::method2"; }
};

class Facade
{
	Subsystem1 sub1;
	Subsystem3 *sub3;

public:

	Facade() { sub3 = new Subsystem3(); }
	~Facade() { delete sub3; }

	void easyToUseMethod1() 
	{
		sub1.method1();
		cout << sub3->method2() << endl;
	}

	void easyToUseMethod2()
	{
		SubsystemB subB;
		subB.methodC();
		sub1.method1();
	}
};

int main()
{
	Facade facade;
	facade.easyToUseMethod1();
	facade.easyToUseMethod2();

	return 0;
}