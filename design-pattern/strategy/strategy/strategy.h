#pragma once
#include<iostream>
using namespace std;

class Strategy {
public:
	virtual void absInterface() = 0;
};
class ConcreteStrategy1 :public Strategy {
public:
	void absInterface(){
		cout << "ConcreteStrategy1:: interface";
	}
};
class ConcreteStrategy2 :public Strategy {
public:
	void absInterface(){
		cout << "ConcreteStrategy2:: interface";
	}
};