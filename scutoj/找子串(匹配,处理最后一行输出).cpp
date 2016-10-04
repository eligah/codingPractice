#include<iostream>
#include<vector>
#include<iterator>
#include<string>
using namespace std;
bool ifSubstring(string st1,string st2){
	int st1Length = st1.size();
	int st2Length = st2.size();
	if (st1Length > st2Length) {
		cout << "No";
		return false;
	}
	else {
		int s1Pos = 0;
		int s2Pos = 0;
		while(s2Pos<st2Length) {
			if (st1[s1Pos] == st2[s2Pos]) {
				++s1Pos;
				++s2Pos;
			}
			else {
				++s2Pos;
			}
		}
		if (s1Pos == st1Length) {
			cout << "Yes";return true;
		}			
		else {
			cout << "No";return false;
		}
	}

}
int main(){
	string st1, st2;
	while (cin>>st1>>st2) {
		if (st1 == "" || st2 == "")
			return 0;
		ifSubstring(st1, st2);
		cout << endl;
	}
	return 0;
}