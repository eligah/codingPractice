#include<iostream>
#include<vector>
#include<initializer_list>

using namespace std;


class Polynomial {
	friend Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);
	friend Polynomial operator*(const Polynomial& lhs,double n);
	friend ostream& operator<<(ostream& os,  Polynomial &rhs);
private:
	vector<double> coefficients;
public:
	Polynomial() {};
	Polynomial(initializer_list<double> init) :coefficients(init){};
	void swap(Polynomial& rls);
	Polynomial& operator=( Polynomial& rls);
	static Polynomial xToTheTower(int n);
	void print(ostream&);
	Polynomial& operator*=(double n);
	Polynomial& operator+=(const Polynomial& rhs);
};