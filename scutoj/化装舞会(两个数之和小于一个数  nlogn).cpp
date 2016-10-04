#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;
int main(){
	int cows = 0;
	int maxLength = 0;
	cin >> cows >> maxLength;
	vector<int> cowcoll;
	int eachcowlength = 0;
	for (int i = 0; i < cows; i++) {
		cin >> eachcowlength;
		cowcoll.push_back(eachcowlength);
	}


	sort(cowcoll.begin(), cowcoll.end());
	cowcoll.erase(upper_bound(cowcoll.begin(), cowcoll.end(), maxLength), cowcoll.end());


	int totalnum = 0;
	vector<int>::iterator cowCurr;
	int cntTurn = 0;
	for (cowCurr=cowcoll.begin(); cowCurr != cowcoll.end()-1; ++cowCurr) {
		if (*cowCurr <= maxLength - *cowCurr) {
			int cntTurn = distance(cowCurr, upper_bound(cowCurr, cowcoll.end(), maxLength - *cowCurr)) - 1;
			totalnum += cntTurn;
			cntTurn = 0;
		}
	}
	cout << totalnum;
}