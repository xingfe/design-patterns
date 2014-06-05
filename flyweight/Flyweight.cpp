#include <iostream>
#include <string>
#include <map>
#include <set>


using namespace std;

class Flyweight
{
	string state;
public:
	Flyweight(const string& s) { state = s; }
	~Flyweight() {}
	string doSomething(const string& s) { return s + " " + state; }
};

class FlyweightFactory
{
	map<string, Flyweight*> flyweights;
	void relaseFlyweights()
	{
		map<string, Flyweight*>::iterator it = flyweights.begin();
		for (; it != flyweights.end(); ++it)
		{
			delete it->second;
		}
	}
	bool isFlyweightExist(const string& key)
	{
		map<string, Flyweight*>::iterator it;
		it = flyweights.find(key);
		return it != flyweights.end();
	}
	Flyweight* createFlyweight(const string& key)
	{
		return new Flyweight(key);
	}
public:
	FlyweightFactory() {}
	~FlyweightFactory() { relaseFlyweights(); }

	Flyweight* getFlyweight(string key)
	{
		if (isFlyweightExist(key))
			return flyweights[key];

		Flyweight* newFlyweight = createFlyweight(key);
		flyweights[key] = newFlyweight;

		return newFlyweight;
	}

	int getFlyweightsNumber() { return flyweights.size(); }
};

int main()
{
	FlyweightFactory factory;

	set<string> colors;
	colors.insert("red");
	colors.insert("green");
	colors.insert("blue");

	set<string> hues;
	hues.insert("pale");
	hues.insert("dark");
	hues.insert("light");

	set<string>::iterator i;
	for (i = hues.begin(); i != hues.end(); ++i)
	{
		set<string>::iterator j;
		for (j = colors.begin(); j != colors.end(); ++j)
		{
			Flyweight *flyweight = factory.getFlyweight(*j);
			cout << flyweight->doSomething(*i) << endl;
		}
	}
	cout << "getFlyweightsNumber : ";
	cout << factory.getFlyweightsNumber() << endl;

	return 0;
}