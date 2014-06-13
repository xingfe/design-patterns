#include <iostream>
#include <string>

using namespace std;

class Context
{
	class State
	{
	public:
		virtual void handle() = 0;
		virtual ~State() {}
	};

	class ConcreteState1 : public State
	{
	public:
		void handle() { cout << "ConcreteState1"; }
	};

	class ConcreteState2 : public State
	{
	public:
		void handle() { cout << "ConcreteState2"; }
	};

	State *state;
	bool bState;
public:
	Context() : state(new ConcreteState1), bState(false) {}
	~Context() { delete state; }
	void request() { return state->handle(); }
	void changeStateOperation()
	{
		delete state;
		bState = !bState;

		if (bState)
			state = new ConcreteState2;
		else
			state = new ConcreteState1;
	}
};


int main()
{
	Context ctx;
	ctx.request();
	cout << endl;
	ctx.changeStateOperation();
	ctx.request();
	cout << endl;
	ctx.changeStateOperation();
	ctx.request();

	return 0;
}