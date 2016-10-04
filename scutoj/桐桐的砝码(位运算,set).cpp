#include<iostream>
#include<bitset>
#include<set>
#include<math.h>
#include<iterator>
using namespace std;
int main(){
	int fama[6] = { 2, 3, 5, 7, 10, 15 };
	set<int> coll;
	int sum = 0;
	for (int i = 1; i <= 63; i++) {
		bitset<6> a(i);
		for (int j = 0; j < 6; j++) {
			sum = sum + fama[j] * a[j];
		}
		coll.insert(sum);
		sum = 0;
	}
	cout << coll.size();
}
