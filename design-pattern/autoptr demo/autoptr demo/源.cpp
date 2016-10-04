#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<functional>
class findPivot {
	bool operator()(int a, int b){
		return a > b;
	}
};
using namespace std;
int search(const vector<int>& coll, int target){
	auto p=is_sorted_until(coll.begin(), coll.end(), greater<int>());
	advance(p,1);
	int dis = distance(coll.begin(), p);
	rotate(coll.begin(), p, coll.end());
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	auto final=find(coll.begin(), coll.end(), target);
	if (final == coll.end())
		return -1;
	else {
		int finaldis = distance(coll.begin(), final);
		return (finaldis + dis) % coll.size();
	}
}


int main(){
	vector<int> l1 = { 2, 3, 4, 5, 1 };
	cout<<search(l1, 3);
	cout << endl;
}