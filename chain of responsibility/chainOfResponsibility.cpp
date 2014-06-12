#include <iostream>
#include <string>

using namespace std;

enum RequestType
{
	REQ_DIRECTOR,
	REQ_MANAGER,
	REQ_WORKER
};

class Reqest 
{
	string order;
public:
	Reqest(const string & desc) : order(desc) {}
	RequestType reqType;
	const string& getOrder() const { return order; }
};

class ChainHandler
{
	ChainHandler *nextChain;
	void sendReqestToNextHandler(const Reqest & req)
	{
		if (nextChain != NULL)
			nextChain->handle(req);
	}
protected:
	virtual bool canHandleRequest(const Reqest & req) = 0;
	virtual void doWork(const Reqest & req) = 0;
public:
	ChainHandler() { nextChain = NULL; }
	void setNextChain(ChainHandler *next) { nextChain = next; }
	void handle(const Reqest & req)
	{
		if (canHandleRequest(req))
			doWork(req);
		else
			sendReqestToNextHandler(req);
	}
};

class Director : public ChainHandler
{
protected:
	bool canHandleRequest(const Reqest & req)
	{
		return req.reqType == RequestType::REQ_DIRECTOR;
	}
	void doWork(const Reqest & req)
	{
		cout << "Director is handle reqest: " << req.getOrder() <<  endl;
	}
};

class Manager : public ChainHandler
{
protected:
	bool canHandleRequest(const Reqest & req)
	{
		return req.reqType == RequestType::REQ_MANAGER;
	}
	void doWork(const Reqest & req)
	{
		cout << "Manager is handle reqest: " << req.getOrder() << endl;
	}
};

class Worker : public ChainHandler
{
protected:
	bool canHandleRequest(const Reqest & req)
	{
		return req.reqType == RequestType::REQ_WORKER;
	}
	void doWork(const Reqest & req)
	{
		cout << "Worker is handle reqest: " << req.getOrder() << endl;
	}
};

int main()
{
	Director director;
	Manager manager;
	Worker worker;

	director.setNextChain(&manager);
	manager.setNextChain(&worker);

	Reqest req("Do task #3212");
	req.reqType = RequestType::REQ_WORKER;

	director.handle(req);

	return 0;
}