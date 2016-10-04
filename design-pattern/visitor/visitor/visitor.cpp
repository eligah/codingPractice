#include"Ivisitor.h"
#include"element.h"

void Visitor::visit(CElement1 *e1){
	e1->doSth();
}
void Visitor::visit(CElement2 *e2){
	e2->doSth();
}