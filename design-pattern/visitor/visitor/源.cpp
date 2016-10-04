#include"element.h"
#include"Ivisitor.h"

int main(){
	ObjectStucture o1;
	 Visitor v1;
	 Ivisitor& vi = v1;
	for (shared_ptr<Element> elem : o1.elist) {
		elem->accept(vi);
	}

	cout << endl;
}