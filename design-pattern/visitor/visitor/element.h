#pragma once
//#include"Ivisitor.h"
#include<list>
#include<random>
#include<ctime>
#include<iostream>
#include<memory>
using namespace std;
class Ivisitor;

class Element {
public:
	virtual void doSth() = 0;
	virtual void accept(Ivisitor	&visitor) = 0;
};

class CElement1:public Element {
public:
	void doSth();
	void accept(Ivisitor &visitor);
};
class CElement2 :public Element {
public:
	void doSth();
	void accept(Ivisitor &visitor);
};

class	ObjectStucture {
public:
	list<shared_ptr<Element> >elist;
	ObjectStucture(){
		srand(time(0));
		for (int i = 0; i < 100; i++) {
			int randnum = rand() % 100 + 1;
			if (randnum>50) {
				shared_ptr<Element> e1(new CElement1());
				elist.push_back(e1);
			}
			else {
				shared_ptr<Element> e1(new CElement2());
				elist.push_back(e1);
			}
		}
	}
};