#include <iostream>
#include <string>

using namespace std;

enum RequestType
{
	REQ_CEO,
	REQ_MANAGER,
	REQ_WORKER
};

class Reqest {
public:
	RequestType reqType;
};

class ChainHandler 
{
	ChainHandler *nextChain;

protected:

	void sendReqestToNextHandler(const Reqest & req)
	{
		if (nextChain != NULL)
			nextChain->handle(req);
	}

public:
	ChainHandler() { nextChain = NULL; }
	virtual void setNextChain(ChainHandler *nextChain) { this->nextChain = nextChain; }
	virtual void handle(const Reqest & req) = 0;
};

class CEO : public ChainHandler
{
public:
	void handle(const Reqest & req) 
	{
		if (req.reqType == RequestType::REQ_CEO)
		{
			cout << "CEO is handle reqest" << endl;
		}
		else
		{
			sendReqestToNextHandler(req);
		}
	}
};

class Manager : public ChainHandler
{
public:
	
	void handle(const Reqest & req)
	{
		if (req.reqType == RequestType::REQ_MANAGER)
		{
			cout << "Manager is handle reqest" << endl;
		}
		else
		{
			sendReqestToNextHandler(req);
		}
	}
};

class Worker : public ChainHandler
{
public:
	void handle(const Reqest & req)
	{
		if (req.reqType == RequestType::REQ_WORKER)
		{
			cout << "Worker is handle reqest" << endl;
		}
		else
		{
			sendReqestToNextHandler(req);
		}
	}
};


int main()
{
	CEO ceo;
	Manager manager;
	Worker worker;

	ceo.setNextChain(&manager);
	manager.setNextChain(&worker);

	Reqest req;
	req.reqType = RequestType::REQ_WORKER;

	ceo.handle(req);

	return 0;
}