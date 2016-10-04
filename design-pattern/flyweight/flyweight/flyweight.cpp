#include"flyweight.h"
#include<iostream>

string Flyweight::getInstance(){
	return s_;
}

Flyweight::~Flyweight(){
	cout << "distraction of flyweight";
}
void Flyweight::op(const string& s){
	cout << "base ::op()";
}

ConcreteFlyweight::ConcreteFlyweight(const string& s) :Flyweight(s){
	cout << "ConcreteFlyweight " << s << " has builded" << endl;
};

void ConcreteFlyweight::op(const string& s){
	cout << "the state of " << s << " is " << getInstance() << endl;
}

ConcreteFlyweight::~ConcreteFlyweight(){
	cout << "distruction of concreteflyweight";
}

