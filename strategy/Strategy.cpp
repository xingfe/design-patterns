#include <iostream>
#include <string>

using namespace std;

class Strategy
{
public:
	virtual void execute() = 0;
};

class Strategy1 : public Strategy
{
public:
	void execute() { cout << "Strategy1" << endl; }
};

class Strategy2 : public Strategy
{
public:
	void execute() { cout << "Strategy2" << endl; }
};

class Context
{
	Strategy * strategy = NULL;
public:
	Context(Strategy& s) : strategy(&s) {}
	void setStrategy(Strategy& s) { strategy = &s; }
	void executeStrategy() { strategy->execute(); }
};

int main()
{
	Strategy1 strategy1;
	Strategy2 strategy2;

	Context context(strategy1);
	context.executeStrategy();
	context.setStrategy(strategy2);
	context.executeStrategy();

	return 0;
}