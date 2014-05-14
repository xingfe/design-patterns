#include <iostream>
#include <string>

using namespace std;

class State
{
	bool isPrince;

public:
	State() :isPrince(false) {}

	std::string whoIYou()
	{
		std:string msg;

		if (false == isPrince)
			msg = "Frog";
		else
			msg = "Prince";

		return msg;
	}

	void princesKiss() { isPrince = true; }
};



int main()
{
	State state;
	cout << state.whoIYou() << endl;
	// after call this method state object change his behavior
	state.princesKiss();
	cout << state.whoIYou() << endl;

	return 0;
}