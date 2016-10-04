#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;

struct PersonInfo {
	vector<string> tel;
	string name;
};
istream& getFromFile(istream& in, vector<PersonInfo> &st1){
	auto backetinsertter = back_inserter(st1);
	string stemp, tel;
	while (getline(in, stemp)) {
		PersonInfo p1;
		istringstream record(stemp);
		record >> p1.name;
		while (record >> tel) {
			p1.tel.push_back(tel);
		}
		st1.push_back(p1);
	}
	in.clear();
	return in;
}
bool isfommated(const string& nums){
	for (auto c : nums) {
		if (!isdigit(c)) {
			return false;
		}
	}
	return true;
}

void test(vector<PersonInfo> &coll, ostream &os){
	for (const auto &entry : coll) {
		ostringstream format, badNums;
		for (const auto &nums : entry.tel) {
			bool formatflag = isfommated(nums);
			if (formatflag) {
				format << " " << nums;
			}
			else
				badNums << " " << nums;
		}
			if (badNums.str().empty()) {
				os << entry.name << " " << format.str() << endl; 
			}
			else {
				cerr << "input error: " << entry.name
					<< " invalid number is :" << badNums.str() << endl;
			}
	}
}
int main(){
	ifstream f1("haha.txt");
	vector<PersonInfo> st1;
	getFromFile(f1, st1);
	test(st1, cout);
		system("pause");


}