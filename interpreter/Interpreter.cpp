#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Context 
{
	string input;
	string output;

public:
	Context(const string & in) { input = in; }

	void setInput(const string & in) { input = in; }
	string getInput() { return input; }

	void setOutput(const string & out) { output = out; }
	string getOutput() { return output; }
};

class AbstractExpresion 
{
	string replaceString(const string& str, const string& search,  const string& replace) 
	{
		string s = str;
		size_t pos = 0;
		while ((pos = s.find(search, pos)) != string::npos)
		{
			s.replace(pos, search.length(), replace);
			pos += replace.length();
		}
		return s;
	}

public:
	virtual void interpret(Context & context)
	{
		string output = replaceString(context.getInput(), search(), replase());
		context.setInput(output);
		context.setOutput(output);
	}

	virtual string search() = 0;
	virtual string replase() = 0;
};

class AExpression : public AbstractExpresion
{
public:
	string search() { return "A"; }
	string replase() { return "AA"; }
};

class BExpression : public AbstractExpresion
{
public:
	string search() { return "B"; }
	string replase() { return "BB"; }
};

int main()
{
	Context context("A*B+C");
	AExpression ae;
	BExpression be;

	vector<AbstractExpresion*> list;
	list.push_back(&ae);
	list.push_back(&be);
	vector<AbstractExpresion*>::iterator it = list.begin();
	for (; it != list.end(); ++it)
	{
		(*it)->interpret(context);
	}

	cout << context.getOutput();

	return 0;
}