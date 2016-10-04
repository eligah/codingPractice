#pragma once
class Handler {
public:
	virtual ~Handler();
	virtual void handleRequest() = 0;
	void setSuccessor(Handler* succ);
	Handler* getSuccessor();
protected:
	Handler();
	Handler(Handler* succ);
private:
	Handler* succ_;
};

class HandlerA :public Handler {
public:
	virtual void  handleRequest();
	virtual ~HandlerA();
	HandlerA(Handler* succ);
	HandlerA();
};

class HandlerB :public Handler {
public:
	virtual void  handleRequest();
	virtual ~HandlerB();
	HandlerB(Handler* succ);
	HandlerB();
};
