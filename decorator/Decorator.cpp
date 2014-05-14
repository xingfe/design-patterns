#include <iostream>
#include <string>

using namespace std;

class ClientInterface
{
public:
	virtual std::string method() = 0;
};

class ClientInterfaceImpl : public ClientInterface
{
	virtual std::string method() { return "pattern"; }
};

class Decorator : public ClientInterface
{
	ClientInterface & innerInstance;

public:
	Decorator(ClientInterface & dec) : innerInstance(dec) {}
	virtual std::string method() { return "Decorator " + innerInstance.method() + "\n"; }
};


int main()
{
	ClientInterfaceImpl Impl1;
	Decorator Impl2(Impl1);
	Decorator Impl3(Impl2);

	ClientInterface* Impl = NULL;
	
	Impl = &Impl2;
	cout << Impl->method();

	Impl = &Impl3;
	cout << Impl->method();

	return 0;
}