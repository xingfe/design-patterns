#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Component 
{
public:
	virtual void print() = 0;
};

class Composite : public Component
{
	string name;
	vector<Component*> elements;
public:
	Composite(string s) : name(s) {}

	void add(Component* element) { elements.push_back(element); }
	void remove(Component* element) 
	{ 
		elements.erase(std::remove(elements.begin(), elements.end(), element), elements.end());
	}
	Component* getChild(int index) { return elements[index]; }

	void print() 
	{
		cout << name << endl;
		vector<Component*>::iterator it;
		for (it = elements.begin(); it != elements.end(); ++it)
			(*it)->print();
	}
	
};

class Leaf : public Component
{
	string name;
public:

	Leaf(string s) : name(s) {}
	void print() 
	{
		cout << name << endl;
	}

};

class Direcotory : public Composite 
{
public:
	Direcotory(string s) : Composite(s) {}
};
class File : public Leaf 
{
public:
	File(string s) : Leaf(s) {}
};

int main()
{
	Direcotory root("/");
	Direcotory usr("usr");
	Direcotory home("home");
	Direcotory dev("dev");
	File null("null");

	root.add(&usr);
	root.add(&dev);
	root.add(&home);
	dev.add(&null);
	
	root.print();

	return 0;
}