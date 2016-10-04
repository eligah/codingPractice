#pragma once
#include<string>
using namespace std;
class Flyweight {
public:
	virtual void op(const string& existState);
	virtual ~Flyweight();
	string getInstance();
protected:
	Flyweight(string s) :s_(s){};
private:
	string s_;
};

class ConcreteFlyweight :public Flyweight {
public:
	virtual void op(const string& existState);
	virtual ~ConcreteFlyweight();
	ConcreteFlyweight(const string& s);
};

