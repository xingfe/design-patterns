#include <iostream>
#include <string>

using namespace std;

class AdapterInterface
{
public:
	virtual std::string method() = 0;
};

class Adaptee
{
public:
	std::string method1() { return "Adapter";  }
	std::string method2() { return " pattern"; }
};

class AdapterImplementation : public AdapterInterface
{
	Adaptee adapteeInstance;

public:
	virtual std::string method() 
	{ 
	    return adapteeInstance.method1() + adapteeInstance.method2();
        }
};

int main()
{
	AdapterImplementation adapImpl;
	AdapterInterface& adapter = adapImpl;
	cout << adapter.method();

	return 0;
}