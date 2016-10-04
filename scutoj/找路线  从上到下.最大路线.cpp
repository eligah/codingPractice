#include<iostream>
#include<vector>
using namespace std;
int max(int x, int y){
	return x > y ? x : y;
}
int factoral(int n){
	return (1 + n)*n / 2;
}
int getValue(int rootpos, vector<int> &coll, int level){
	if (rootpos + level >= coll.size()) {
		return coll[rootpos];
	}
	else {
		return coll[rootpos] + max(
			getValue(rootpos + level, coll, level + 1),
			getValue(rootpos + level + 1, coll, level + 1));
	}
}
int main(){
	int level;
	cin >> level;
	vector<int> coll;
	int cnt = factoral(level);
	int itemp = 0;
	while (cnt--) {
		cin >> itemp;
		coll.push_back(itemp);
	}
	cout << endl;
	int value = getValue(0, coll, 1);
	cout << value;
}