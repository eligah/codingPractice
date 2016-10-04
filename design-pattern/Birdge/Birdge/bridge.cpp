#include<iostream>
#include<memory>
using namespace std;

class Road;

class Car {
public :
	virtual void run() = 0;
};

class Bus :public Car {
	virtual void run(){
		cout << "bus is running on ";
	}
};

class Taxi :public Car {
	virtual void run(){
		cout << "Taxi is running on ";
	}
};
class Road {
protected:
	shared_ptr<Car> car_;
public:
	virtual void Run() = 0;
	void setCar(shared_ptr<Car> car){
		car_ = car;
	}
};

class Highway :public Road{
public:
	virtual void Run(){
		car_->run();
		cout << " the highway \n";
	}
};

class Street :public Road {
public:
	virtual void Run(){
		car_->run();
		cout << " the street \n";
	}
};

class Person {
protected:
	shared_ptr<Road> road_;
public:
	virtual void run() = 0;
	void setRoad(shared_ptr<Road> road){
		road_ = road;
	}
};
class Man :public Person {
	virtual void run(){
		cout << "man drives a ";
		road_->Run();
	}
};
class Woman :public Person {
	virtual void run(){
		cout << "woman drives a ";
		road_->Run();

	}
};

int main(){
	shared_ptr<Car> car1 = shared_ptr<Car>(new Bus());
	shared_ptr<Road> r1 = shared_ptr<Road>(new Street());
	shared_ptr<Person> p1 = make_shared<Man>(Man());
	p1->setRoad(r1);
	r1->setCar(car1);
	p1->run();
	system("pause");
}