#include <iostream>
#include <algorithm>
using namespace std;

int p[1001] = { 0, };
int dp[1001][1001] = { 0, };
int mdp[1001] = { 0, };

int main() {
	int num;


	cin >> num;

	for (int i = 1; i <= num; i++) {
		cin >> p[i];
	}

	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {
			if (i >= j) { 
				dp[i][j] = mdp[i - j] + p[j];
			}
			else {
				dp[i][j] = 0;
			}
		}
		mdp[i] = *max_element(dp[i], dp[i] + num + 1);
	}

	cout << mdp[num];

	return 0;
}
