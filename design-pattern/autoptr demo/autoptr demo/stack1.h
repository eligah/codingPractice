#ifndef STACK1_H
#define STACK1_H


#include<deque>
#include<exception>
using namespace std;
class ReadEmptyStack :public exception {
public:
	virtual const char* what()
	{
		return "the stack is empty";
	}
};
template<typename T>
class Stack2 {
protected: deque<T> c;

public:
	Stack2(){};
	//Stack2(const stack<T>& coll) :c(coll){}
	typename deque<T>::size_type size(){
		return c.size();
	}
	bool empty(){
		return c.empty();
	}

	T pop(){
		if (c.empty()) {
			cout << "no elememt\n";
			throw ReadEmptyStack();
		}
		else {
			T elem(c.back());
			c.pop_back();
			return elem;
		}
	}
	T& top(){
		if (c.empty()) {
			cout << "no elememt\n";
			throw ReadEmptyStack();
		}
		else {
			return c.back();
		}
	}

	void push(const T& elem){
		c.push_back(elem);
	}

};

#endif // !STACK1
