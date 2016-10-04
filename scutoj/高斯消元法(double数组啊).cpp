#include<iostream>
using namespace std;

int main(){
	double a[3][4];
	for (int i = 0; i <= 2;i++)
	for (int j = 0; j <= 3; j++) {
		a[i][j] = 0;
	}
	for(int i = 0; i <= 2; i++)
	for (int j = 0; j <= 3; j++){
			cin >> a[i][j];
	}
	for (int i=0; i <= 1; i++) {
		for (int j = i + 1; j <= 2; j++) {
			for (int k = 3; k >= i; k--) {
				a[j][k] = a[j][k] - a[i][k] * a[j][i] / a[i][i];
			}
		}
	}
	double result[3] = { 0, 0, 0 };
	for (int row = 2; row >= 0; row--) {
		for (int k = 2; k > row; k--) {
			a[row][3] -= a[row][k] * result[k];
		}
		result[row] = a[row][3] / a[row][row];
	}
	for (int i = 0; i <= 2;i++)
	if (i != 2) cout<<result[i] << " ";
	else cout << result[i] << endl;

}