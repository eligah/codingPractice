#include<iostream>
#include"Handler.h"

using namespace std;

int main(){
	Handler* h1 = new HandlerA();
	Handler* h2 = new HandlerB();
	h1->setSuccessor(h2);
	h1->handleRequest();
	cout << h2->getSuccessor();
	delete h1;
	cout << h2->getSuccessor();
	cout << endl;

}