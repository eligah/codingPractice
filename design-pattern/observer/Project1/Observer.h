#pragma once
#include<string>
class Subject;
using namespace std;

class Observer {
public:
	virtual void update(Subject* sub) = 0;
	virtual void printInfo();
	virtual ~Observer();
protected:
	Observer();
};

class COb :public Observer {
public:
	COb();
	virtual ~COb();
	void update(Subject* sub);
	void printInfo();
private:
	string m_state;
};
