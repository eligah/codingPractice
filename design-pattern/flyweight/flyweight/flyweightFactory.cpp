#include"flyweightFactory.h"
#include<iostream>
using namespace std;
Flyweight*  FlyweightFactory::getFlyweight(const string& key){
	for (Flyweight* elemp : flys_) {
		if (elemp->getInstance() == key) {
			cout << "key has already been constructed" << endl;
			return elemp;
		}
	}
	cout << "not find new one" << endl;
	Flyweight* fn = new ConcreteFlyweight(key);
	flys_.push_back(fn);
	return fn;
}
