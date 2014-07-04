#include <iostream>

using namespace std;

class ApplicationFramework
{
protected:
	virtual void step1() = 0;
	virtual void step2() = 0;
public:
	void templateMethod() 
	{
		step1();
		step2();
	}
};

class Application : public ApplicationFramework
{
protected:
	void step1() { cout << "Template method" << endl; }
	void step2() { cout << "design pattern" << endl; } 
};

int main()
{
	Application app;
	app.templateMethod();

	return 0;
}