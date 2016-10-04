#include"element.h"
#include"Ivisitor.h"
void CElement1::doSth(){
	cout << "this is c1\n";
}
void CElement1::accept(Ivisitor &visitor){
	visitor.visit(this);
}

void CElement2::doSth(){
	cout << "this is c2\n";
}
void CElement2::accept(Ivisitor &visitor){
	visitor.visit(this);
}
