#pragma once
#include<list>
#include<memory>
using namespace std;
class Observer;
class Subject {
public:
	Subject();
	virtual ~Subject();
	virtual void attach(Observer* v);
	virtual void detach(Observer* v);
	virtual string getState();
	virtual void setState(const string& s);
	virtual void notify();
protected:
	string st_;
private:
	shared_ptr<list<Observer*> >  obvs;
};


class ConcreteSubject :
	public Subject {
public:
	ConcreteSubject();
	virtual ~ConcreteSubject();
	string getState();
	void setState(const string& st);
private:
};	

