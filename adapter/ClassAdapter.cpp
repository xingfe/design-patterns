#include <iostream>
#include <string>

using namespace std;

class ClientInterface
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

class AdapterImplementation : public ClientInterface, private Adaptee
{	
public:
	virtual std::string method() { return method1() + method2(); }
};

int main()
{
	AdapterImplementation adapImpl;
	ClientInterface& adapter = adapImpl;
	cout << adapter.method();

	return 0;
}
