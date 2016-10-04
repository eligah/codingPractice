#pragma once
class CElement1;
class CElement2;
class Ivisitor {
public:
    virtual void visit(CElement1 *e1) = 0;
	virtual void visit(CElement2 *e2) = 0;
};

class Visitor :public Ivisitor {
	void visit(CElement1 *e1);
	void visit(CElement2 *e2);
};