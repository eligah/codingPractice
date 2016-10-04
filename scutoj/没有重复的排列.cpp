#include<iostream>
#include<set>
#include<vector>
#include<iterator>
using namespace std;


void sort(long long a[],int n){
	cout << a[n];
	cout << endl;
}
int main(){
	long long sortTable[21] = {};//定义一个表存储排列个数
	long long re[21] = {};
	for (long i = 1; i <= 18; i++) {
		if (i == 1)
			sortTable[i] = 1;
		else
			sortTable[i] = sortTable[i-1] * i;
	}
	for (int i = 1; i <= 20; i++) {
		if (i == 1)
			re[i] = 0;
		if (i == 2)
			re[i] = 1;
		else
			re[i] = (i - 1)*(re[i - 2] + re[i-1]);
	}
	int size = 0;
	while (cin >> size)
		sort(re, size);
}