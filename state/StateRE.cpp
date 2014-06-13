#include <iostream>
#include <string>

using namespace std;

class Woman 
{
	class Behavior
	{
	public:
		virtual string whoAreYou() = 0;
		virtual ~Behavior() {}
	};
	class Angel : public Behavior
	{
	public:
		string whoAreYou() { return "Angel"; }
		virtual ~Angel() {}
	};
	class Devil : public Behavior
	{
	public:
		string whoAreYou() { return "Devil"; }
		virtual ~Devil() {}
	};

	Behavior *behavior;
public:
	Woman() : behavior(new Angel) {}
	~Woman() { delete behavior; }
	string tellWhoAreYou() { return behavior->whoAreYou(); }
	void lookSheHasTheSameSkirt() 
	{
		delete behavior;
		behavior = new Devil;
	}
	void youLookNiceToday()
	{
		delete behavior;
		behavior = new Angel;
	}
};


int main()
{
	Woman woman;
	cout << woman.tellWhoAreYou() << endl;
	woman.lookSheHasTheSameSkirt();
	cout << woman.tellWhoAreYou() << endl;
	woman.youLookNiceToday();
	cout << woman.tellWhoAreYou() << endl;

	return 0;
}