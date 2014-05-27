#include <iostream>
#include <string>

using namespace std;

class AdapterInterface
{
public:
	virtual string method() = 0;
};

class Adaptee
{
public:
	string method1() { return "Adapter";  }
	string method2() { return " pattern"; }
};

class AdapterImplementation : public AdapterInterface, private Adaptee
{	
public:
	virtual string method() { return method1() + method2(); }
};

int main()
{
	AdapterImplementation adapImpl;
	AdapterInterface& adapter = adapImpl;
	cout << adapter.method();

	return 0;
}
