#include<iostream>


using namespace std;

int main(){
	int aim[4][4];
	int a[4][4];
	for (int i = 0; i <= 3;i++)
	for (int j = 0; j <= 3; j++) {
		a[i][j] = 0;
	}
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++)
			cin >> a[i][j];
	}
	
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++)
			aim[i][j]= a[i][j];
	}

	int i = 0, j = 0, k = 0;
	for (k=0; k < 4; k++) {
		for (i=0; i < 4; i++) {
			for (j=0; j < 4; j++) {
				if (aim[i][j] == 1 || (aim[i][k] *aim[k][j] == 1))
					aim[i][j] = 1;
			}
		}
	}
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			if (j!=3)
			cout << aim[i][j] << " ";
			else {
				cout << aim[i][j]<<endl;
			}
		}			
		
	}
	cout << endl;
}