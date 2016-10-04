#include<iostream>
#include<vector>
#include<iterator>
#include <functional>
#include<string>
#include<algorithm>

using namespace std;
class Tree {
public:
	Tree* left;
	Tree* right;
	double weight;
	string haffmanCode;
	bool operator<(const Tree& rhs){
		return weight < rhs.weight;
	}
};
vector<Tree> initTree(int N){
	Tree temp;
	vector<Tree> TreeList;
	for (int i = 0; i < N; i++) {
		cin >> temp.weight;
		TreeList.push_back(temp);
	}
	return TreeList;
}

//return root of huffman tree;
Tree* buildHuffmanTree(vector<Tree> Treelist){
	while (Treelist.size() > 1) {
		Tree newTree;
		vector<Tree>::iterator firstmin, secondmin;

		firstmin = min_element(Treelist.begin(), Treelist.end());
		Tree* subLTree = new Tree(*firstmin);
		Treelist.erase(firstmin);
		secondmin = min_element(Treelist.begin(), Treelist.end());
		Tree* subRTree = new Tree(*secondmin);
		Treelist.erase(secondmin);

		newTree.left = subLTree;
		newTree.right = subRTree;
		newTree.weight = subLTree->weight + subRTree->weight;

		Treelist.push_back(newTree);
	}
	return new Tree(*Treelist.begin());
}

//haffmantree disstructor
void release(Tree* bt)
{
	if (bt != NULL) {
		release(bt->left);   //释放左子树
		release(bt->right);   //释放右子树
		delete bt;
	}
}

void addhuffmancode(Tree* root, string s){
	if (root != 0) {
		root->haffmanCode = s;
		addhuffmancode(root->left, s + "0");
		addhuffmancode(root->right, s + "1");
	}
}

bool compareTreeValue(const Tree& ls, const Tree& rs){

	return ls.haffmanCode==""&&static_cast<int>(abs(ls.weight - rs.weight)) < 1e6;
}

class CompareTreeValue : public binary_function<Tree, Tree, bool> {
public:
	bool operator () (const Tree& ls, const Tree& rs) const
	{
		return abs(ls.weight - rs.weight) < 0.001&&ls.haffmanCode == "";
	}
};

void traverse(Tree* root,vector<Tree> &list){
	if (root->left == root->right&&root->right==NULL) {//leaves
		vector<Tree>::iterator marchTree = find_if(list.begin(), list.end(), bind2nd(CompareTreeValue(), *root));
		marchTree->haffmanCode=root->haffmanCode;
		return;
	}
	else {
		traverse(root->left, list);
		traverse(root->right, list);
	}
}

void printHuffmancode(const vector<Tree> &list){
	vector<Tree>::const_iterator  iter = list.begin();
	cout << iter->haffmanCode;
	iter++;
	for (; iter != list.end();iter++) {
		cout << endl;
		cout << iter->haffmanCode;
	}
}

int main(){
	int level = 0;
	cin >> level;
	vector<Tree> Treelist = initTree(level);

	Tree* root = buildHuffmanTree(Treelist);
	

	addhuffmancode(root, "");
	traverse(root, Treelist);
	printHuffmancode(Treelist);
	release(root);
	cout << endl;
}