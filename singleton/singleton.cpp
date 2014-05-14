#include <iostream>
#include <string>

using namespace std;

class Singleton
{
private:
	static Singleton s;

	Singleton() {}
	Singleton(const Singleton &);
	Singleton & operator=(Singleton &);

public:

	std::string method() { return "Singleton"; }
	static Singleton & getInstance() { return s; }
};

// inicjalization of class Singleton static variable 
Singleton Singleton::s;


int main()
{
	Singleton& s = Singleton::getInstance();
	std::cout << s.method() << endl;
	return 0;
}
