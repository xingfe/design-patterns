#include <iostream>
#include <vector>

using namespace std;

class Receiver
{
public:
	void action1() { cout << "Command" << endl; }
	void action2() { cout << "design pattern" << endl; }
};

class Command
{
public:
	virtual void execute() = 0;
};

class ConcreteCommand1 : public Command
{
	Receiver & receiver;
public:
	ConcreteCommand1(Receiver & r) : receiver(r) {}
	void execute()
	{
		receiver.action1();
	}
};

class ConcreteCommand2 : public Command
{
	Receiver & receiver;
public:
	ConcreteCommand2(Receiver & r) : receiver(r) {}
	void execute()
	{
		receiver.action2();
	}
};



class Invoker
{
	vector<Command*> commands;
public:
	void addCommand(Command *c) { commands.push_back(c); }
	void executeCommands()
	{
		vector<Command*>::iterator it = commands.begin();
		for (; it != commands.end(); ++it)
		{
			(*it)->execute();
		}
	}
};

int main()
{
	Receiver receiver;
	ConcreteCommand1 command1(receiver);
	ConcreteCommand2 command2(receiver);
	Invoker invoker;

	invoker.addCommand(&command1);
	invoker.addCommand(&command2);

	invoker.executeCommands();

	return 0;
}