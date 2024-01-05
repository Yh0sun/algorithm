#include<iostream>
using namespace std;

int coin[100][100] = { 0 };
int TurnCoin(int a, int b) {
	for (int i = 0; i <= a; i++) {
		for (int j = 0; j <= b; j++) {
			if (coin[i][j] == 0) coin[i][j] = 1;
			else coin[i][j] = 0;
		}
	}
	return 0;
};

int main() {
	int n, m, result = 0;
	char input;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			input = cin.get();
			if (input == '\n')input = cin.get();
			coin[i][j] = input - '0';
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			if (coin[i][j] != 0) {
				result++;
				TurnCoin(i, j);
			}
		}
	}

	cout << result;

	return 0;
}