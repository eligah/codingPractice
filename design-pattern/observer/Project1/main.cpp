#include"Observer.h"
#include"ConcreteSubject.h"
#include<iostream>
using namespace std;

int main(){
	Observer* ob1 = new COb();
	ob1->printInfo();
	Subject* s1 = new ConcreteSubject();
	s1->attach(ob1);
	s1->setState("ya");
	s1->notify();
	ob1->printInfo();

	s1->detach(ob1);
	s1->setState("wawa");
	s1->notify();

	ob1->printInfo();

}