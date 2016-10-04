#include<iostream>
#include<string>

using namespace std;
int findroot(char n, string inorder){
	int index = 0;
	index = inorder.find(n);
	return index;
}

void post(string& pre,int pre_s,int pre_e, string& in,int in_s,int in_e){
	if (pre.length() != in.length())
		return;
	if (pre_s > pre_e)
		return;
	char c = pre[pre_s];
	int k;
	k = findroot(c, in);
	post(pre, pre_s + 1, pre_s + k - in_s, in, in_s, k - 1);
	post(pre, pre_s + k - in_s+1, pre_e, in, k+1, in_e);
	cout << c;
}
int main(){
	string pre, in;
	while (cin>>pre>>in) {
		if (pre == "" || in == "")
			return 0;
		if (pre.length() != in.length())
			return 0;
		post(pre,0,pre.length()-1, in,0,in.length()-1);
		cout << endl;
	}
}