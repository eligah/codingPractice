#pragma once
#include<iostream>
class Strategy;
using namespace std;

class Context{
public:
	Context(Strategy* s) :st_(s){}
	void doAction();
private:
	Strategy* st_;
};