#include"Polynomial.h"
#include<algorithm>
#include<iterator>
void Polynomial::swap(Polynomial& rhs){
	std::swap(coefficients, rhs.coefficients);
}


Polynomial& Polynomial::operator=(Polynomial &rhs){
	Polynomial p(rhs);
	p.swap(*this);
	return *this;
}
Polynomial Polynomial::xToTheTower(int n){
	Polynomial temp;
	while (n--) {
		temp.coefficients.push_back(0);
	}
	temp.coefficients.push_back(1);
	return temp;
}

void Polynomial::print(ostream& os) {
	auto iter = coefficients.rbegin();
	auto e = coefficients.size()-1;

	while (*iter == 0) {
		iter++;
		e--;
	}
	os << *iter++ << "x^" << e--;

	while (iter!=coefficients.rend()) {
		if (*iter==0) {
			iter++;
			e--;
		}
		else {
			os <<","<< *iter++ << "x^" << e--;	
		}
	}
}

Polynomial& Polynomial::operator*=(double n){
	for (auto &item : coefficients) {
		item *= n;
	}
	return *this;
}

Polynomial& Polynomial::operator+=(const Polynomial& rhs){
	while (coefficients.size() < rhs.coefficients.size()) {
		coefficients.push_back(0);
	}
	Polynomial rtemp = rhs;
	while (coefficients.size() > rtemp.coefficients.size()) {
		rtemp.coefficients.push_back(0);
	}
	//ostream_iterator<double> it(cout);
	transform(coefficients.begin(), coefficients.end(),
		rtemp.coefficients.begin(), coefficients.begin(),
		[](double l, double r){return l+r; });
	return *this;
}

ostream& operator<<(ostream& os,  Polynomial &rhs){
	rhs.print(os);
	return os;
}

Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs){
	Polynomial ptemp = lhs;
	ptemp += rhs;
	return ptemp;
}
Polynomial operator*(const Polynomial& lhs, double n){
	Polynomial ptemp = lhs;
	ptemp.operator*= (n);
	return ptemp;
}

