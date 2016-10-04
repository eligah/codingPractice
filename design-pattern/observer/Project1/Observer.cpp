#include "Observer.h"
#include"ConcreteSubject.h"
#include<iostream>
using namespace std;
Observer::Observer()
{
}


Observer::~Observer()
{
}
void Observer::printInfo(){
}

COb::COb(){
	
}
COb::~COb(){
}
void COb::update(Subject* sub){
	this->m_state = sub->getState();
	cout << "the concreteObserver is " << m_state << endl;
}
void COb::printInfo(){
	cout << m_state;
}

