#include"context.h"
#include"strategy.h"
using namespace std;

int main(){
	ConcreteStrategy1 cs1;
	Strategy* s = &cs1;
	Context client(s);
	client.doAction();
	cout << endl;
}