#include <iostream>
#include <vector>

using namespace std;

class Mother;
class Father;
class Child;
class Pet;

class Visitor
{
public:
	virtual void visitMother(Mother& visitable) = 0;
	virtual void visitFather(Father& visitable) = 0;
	virtual void visitChild(Child& visitable) = 0;
	virtual void visitPet(Pet& visitable) = 0;
};

class GrandFather : public Visitor
{
public:
	void visitMother(Mother& visitable)
	{
		cout << "GrandFather try to find out what is wrong with his daughter" << endl;
	};

	void visitFather(Father& visitable)
	{
		cout << "GrandFather have an argument with his son-in-law" << endl;
	}
	void visitChild(Child& visitable)
	{
		cout << "GrandFather read child a fairytale" << endl;
	}

	void visitPet(Pet& visitable)
	{
		cout << "GrandFather gives pet something good to eat" << endl;
	}
};

class Visitable
{
public:
	virtual void accept(Visitor& visitor) = 0;
};


class Mother : public Visitable 
{
public:
	void accept(Visitor &visitor) { visitor.visitMother(*this);  }
};

class Father : public Visitable 
{
public:
	void accept(Visitor &visitor) { visitor.visitFather(*this); }
};

class Child : public Visitable
{
public:
	void accept(Visitor &visitor) { visitor.visitChild(*this); }
};

class Pet : public Visitable
{
public:
	void accept(Visitor &visitor) { visitor.visitPet(*this); }
};


class House : public Visitable 
{
	vector<Visitable*> residents;

public:
	House() {}

	void addResident(Visitable *resident) { residents.push_back(resident); }

	void accept(Visitor &visitor)
	{
		vector<Visitable*>::iterator it = residents.begin();
		for (; it != residents.end(); ++it)
		{
			(*it)->accept(visitor);
		}
	}
};

int main()
{
	GrandFather grandpa;
	Mother mother;
	Father father;
	Child child;
	Pet cat;

	House house;
	house.addResident(&mother);
	house.addResident(&father);
	house.addResident(&child);
	house.addResident(&cat);

	house.accept(grandpa);

	return 0;
}
