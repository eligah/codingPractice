#include "Handler.h"
#include<iostream>
using namespace std;


Handler::Handler()
{
	succ_ = 0;
}

Handler::Handler(Handler* succ) :succ_(succ){}

Handler::~Handler()
{

	delete succ_;
}

void Handler::setSuccessor(Handler* succ){
	succ_ = succ;
}
Handler* Handler::getSuccessor(){
	return succ_;
}

HandlerA::HandlerA()
{
	setSuccessor(0);
}

HandlerA::HandlerA(Handler* succ):Handler(succ){}
void HandlerA::handleRequest(){
	if (getSuccessor() != 0) {
		cout << "transfer it to next obj" << endl;
		getSuccessor()->handleRequest();
	}
	else {
		cout << "handle this request by handlerA" << endl;
	}
}
HandlerA::~HandlerA(){
	cout << "a delete " << endl;
}


HandlerB::HandlerB()
{
	setSuccessor(0);
}

HandlerB::HandlerB(Handler* succ) :Handler(succ){}
void HandlerB::handleRequest(){
	if (getSuccessor() != 0) {
		cout << "transfer it to next obj" << endl;
		getSuccessor()->handleRequest();
	}
	else {
		cout << "handle this request by HandlerB" << endl;
	}
}
HandlerB::~HandlerB(){
	cout << "b delete" << endl;
}

