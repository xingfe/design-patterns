#include <iostream>
#include <string>

using namespace std;

class ClientInterface
{
public:
	virtual string method() = 0;
};

class ClientImplemantation : public ClientInterface
{
public:
	virtual string method() { return "proxy pattern"; }
};


class VirtualProxy : public ClientInterface
{
	ClientImplemantation * impl;

public:
	VirtualProxy() :impl(NULL)  {}

	virtual ~VirtualProxy() { if (impl != NULL) delete impl; }

	virtual string method() 
	{
		// first call method creates object
		if (NULL == impl)
			impl = new ClientImplemantation();

		return impl->method();
	}

};



int main()
{
	VirtualProxy proxy;
	ClientInterface& interf =  proxy;
	cout << interf.method() << endl;
	
	return 0;
}
