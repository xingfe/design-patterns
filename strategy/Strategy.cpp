#include <iostream>
#include <string>

using namespace std;

class Algorithm
{
public:
	virtual void doWork() = 0;
};

class Algorithm1 : public Algorithm
{
public:
	void doWork() { cout << "Algorithm1" << endl; }
};

class Algorithm2 : public Algorithm
{
public:
	void doWork() { cout << "Algorithm2" << endl; }
};


class Context
{
	Algorithm * algrithm = NULL;
public:
	Context(Algorithm& alg) : algrithm(&alg) {}
	void setAlgorithm(Algorithm &alg) { algrithm = &alg; }
	void doWork() { algrithm->doWork(); }
};


int main()
{
	Algorithm1 alg1;
	Algorithm2 alg2;

	Context context(alg1);
	context.doWork();
	context.setAlgorithm(alg2);
	context.doWork();

	return 0;
}