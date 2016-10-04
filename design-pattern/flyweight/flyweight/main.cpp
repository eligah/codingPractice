#include"flyweightFactory.h"
using namespace std;

int main(){
	FlyweightFactory f;
	Flyweight* fp;
	f.getFlyweight("eligah");
	f.getFlyweight("is");
	fp=f.getFlyweight("eligah");
	fp->op("eligah");

}