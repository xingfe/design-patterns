#include <iostream>
#include <string>

using namespace std;

class Subject
{
public:
	virtual string method() = 0;
};

class RealSubject : public Subject
{
public:
	virtual string method() { return "proxy pattern"; }
};


class VirtualProxy : public Subject
{
	RealSubject * impl;

public:
	VirtualProxy() :impl(NULL)  {}

	virtual ~VirtualProxy() { if (impl != NULL) delete impl; }

	virtual string method()
	{
		// first call method creates object
		if (NULL == impl)
			impl = new RealSubject();

		return impl->method();
	}

};

int main()
{
	VirtualProxy proxy;
	Subject& interf = proxy;
	cout << interf.method() << endl;

	return 0;
}