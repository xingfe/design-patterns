#include <iostream>
#include <string>

using namespace std;

//Memento: It holds the internal state of an Originator
class Memento
{
	string state;
public:
	Memento(const string & s) : state(s) {}
	string getState() const { return state; }
	void setState(const string & s) { state = s; }
};

//Originator: It is the one whose state needs to be saved and creates the Memento object.
class Originator
{
	string state;
public:
	Originator() {}
	Memento createMomento() { Memento m(state); return m; }
	void setMomento(const Memento & m) { state = m.getState(); }
};


int main()
{
	Originator orginator;
	Memento memento("memento design pattern");
	orginator.setMomento(memento);
	Memento mem = orginator.createMomento();
	cout << mem.getState();

	return 0;
}