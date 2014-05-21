#include <iostream>
#include <string>

using namespace std;

//Memento: It holds the internal state of an Originator
class Memento
{
	string state;

public:
	Memento(string s) : state(s) {}
	string getState() { return state; }
	void setState(string s) { state = s; }
};

//Originator: It is the one whose state needs to be saved and creates the Memento object.
class Originator
{
	string state;

public:

	Originator() {}
	Memento * createMomento() { return new Memento(state); }
	void setMomento(Memento m) { state = m.getState(); }

};



int main()
{
	Originator org;
	Memento mem("state1");
	org.setMomento(mem);
	Memento * pmem = org.createMomento();
	cout << pmem->getState();
	delete pmem;

	return 0;
}