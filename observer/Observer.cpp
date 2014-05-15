#include <iostream>
#include <string>
#include <set>

using namespace std;

class Subject;

class Observer {
public:
	virtual void update(Subject & subject) = 0;
};

// also knows as Observable in literature
class Subject
{
	string state;
	set<Observer*> observers;

public:
	void attachObserver(Observer *o) { observers.insert(o); }
	void detachObserver(Observer *o) { observers.erase(o); }
	void notifyObservers() 
	{
		set<Observer *>::iterator it;
		for (it = observers.begin(); it != observers.end(); ++it)
		{
			(*it)->update(*this);
		}
	}
	string getState() { return state; }
	void changeState(const string & s) 
	{ 
		state = s;
		notifyObservers();
	}

};

class ObserverImpl : public Observer
{
	string state;

public:

	void update(Subject & sbj)
	{
		state = sbj.getState();
	}

	string getState() { return state; }
};



int main()
{
	ObserverImpl a, b, c;
	Subject subject;

	subject.attachObserver(&a);
	subject.attachObserver(&b);
	subject.attachObserver(&c);

	subject.changeState("Observer pattern");
	cout << a.getState() << endl;
	cout << b.getState() << endl;
	cout << c.getState() << endl;

	return 0;
}