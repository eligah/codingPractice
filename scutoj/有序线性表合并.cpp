#include<iostream>
#include<set>
#include<vector>
#include<iterator>
using namespace std;

void cont(){
	vector<int> coll1, coll2;
	int length1, length2;
	int temp = 0;
	cin >> length1;
	for (int i = 0; i < length1; i++) {

		cin >> temp;
		coll1.push_back(temp);
	}
	cin >> length2;
	for (int i = 0; i < length2; i++) {
		cin >> temp;
		coll2.push_back(temp);
	}

	vector<int> vcoll;
	int i = 0, j = 0;
	while (i < coll1.size() || j < coll2.size()) {
		if (i < coll1.size() && j < coll2.size()) {
			if (coll1[i] < coll2[j])
				vcoll.push_back(coll1[i++]);
			else
				vcoll.push_back(coll2[j++]);
		}
		if (i >= coll1.size() && j<coll2.size()) {
			vcoll.push_back(coll2[j++]);
		}
		if (j >= coll2.size() && i<coll1.size()) {
			vcoll.push_back(coll1[i++]);
		}
	}
	vector<int>::iterator iter;
	for (iter = vcoll.begin(); iter != vcoll.end(); iter++) {
		if (iter + 1 != vcoll.end())
			cout << *iter << " ";
		else
			cout << *iter;
	}
	cout << endl;
}

int main(){
	int n;
	cin >> n;
	for (int p = 1; p <= n; p++)
		cont();
	cout << endl;
}
