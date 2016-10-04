#include<iostream>
#include"Polynomial.h"
using namespace std;
int main(){
	Polynomial p1{ 1, 2, 3, 4 };//initallization
	cout << p1;
	cout << endl;
	Polynomial p5 = Polynomial::xToTheTower(5);
	p5.print(cout);
	cout << endl;
	p5 += p1;
	cout << p5;
	cout << endl;
	//cout << endl;
	//cout << p5;
	cout << p5 * 10;//mutilple
	cout << endl;

	p1 = p5;//assignment
	cout << p1;
	system("pause");
}