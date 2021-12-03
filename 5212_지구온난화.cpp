#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
char arr[10][10];
int r, c;
bool disappear(int a, int b);

int main() {
	int count = 0;
	int resulti[100], resultj[100];
	char later50[10][10];

	memset(later50, '.', sizeof(char) * 100);

	cin >> r >> c;

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> arr[i][j];

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 'X' && !disappear(i, j)) {
				later50[i][j] = 'X';
				resulti[count] = i;
				resultj[count] = j;
				count++;
			}
		}
	}
		
	sort(resulti, resulti + count);
	sort(resultj, resultj + count);
	int maxi = resulti[count - 1];
	int maxj = resultj[count - 1];

	for (int i = resulti[0]; i <= maxi; i++) {
		for (int j = resultj[0]; j <= maxj; j++) {
			cout << later50[i][j];
		}
		if (i != maxi) cout << endl;
	}
	return 0;
}

bool disappear(int a,int b) {
	int drt[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
	int count = 0;

	for (int i = 0; i < 4; i++) {
		int x = a + drt[i][0]; 
		int y = b + drt[i][1];
		
		if (x < 0 || x >= r || y < 0 || y >= c)count++;
		else {
			if (arr[x][y] == '.')count++;
		}
	}
	if (count >= 3) return true;
	else return false;
}