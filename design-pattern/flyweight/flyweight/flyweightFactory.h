#pragma once
#include"flyweight.h"
#include<vector>

class FlyweightFactory {
public:
	Flyweight* getFlyweight(const string& key);
private:
	vector<Flyweight*> flys_;
};