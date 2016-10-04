#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<fstream>
#include<sstream>
#include<algorithm>
using namespace std;
void bulid_map(ifstream& in,map<string,string>& m){
	string key, value;
	while (in >> key&&getline(in, value)) {
		if (value.size()>0)
		m[key] = value.substr(1);
		else {
			throw runtime_error("no rules for words: " + key);
		}
	}
}
const string& replace_words(const string& st1, map<string, string>& m){
	auto map_it = m.find(st1);
	if (map_it != m.end()) {
		return map_it->second;
	}
	else
		return st1;
}

int main(){
	ifstream fin("in.txt");
	map<string, string> replace_list;
	bulid_map(fin, replace_list);
	cout << endl;
	fin.close();
	string aline = "";
	string word = "";
	fin.open("out.txt", ios::in);
	while (getline(fin,aline) ){
		istringstream s(aline);
		string row;
		while (s>>word) {
			word = replace_words(word, replace_list);
			row = row + " " + word;
		}
		cout << row;
		cout << endl;
	}
	cout << endl;
}
