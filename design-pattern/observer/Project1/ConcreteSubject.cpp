#include "ConcreteSubject.h"
#include"Observer.h"
#include<iostream>
using namespace std;

Subject::Subject()
{
	obvs = make_shared<list<Observer*> >();
}

Subject::~Subject()
{
}
void Subject::attach(Observer* o){
	obvs->push_front(o);
	cout << "attach the observer " << endl;
}
void Subject::detach(Observer* o){
	if (o!=0)
	obvs->remove(o);
	cout << "detach the observer" << endl;
}
void Subject::notify(){
	auto iter = obvs->begin();
	for (; iter != obvs->end(); iter++) {
		(*iter)->update(this);
	}
}
void Subject::setState(const string& st)
{
	cout << "sub::set State" << endl;
}
string Subject::getState()
{
	cout << "sub::get State" << endl;
	return "";
}

ConcreteSubject::ConcreteSubject()
{
	st_ = "";
}


ConcreteSubject::~ConcreteSubject()
{
}

string ConcreteSubject::getState()
{
	return st_;
}
void ConcreteSubject::setState(const string& st)
{
	st_= st;
}

