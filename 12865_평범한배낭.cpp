#include <iostream>
#include <algorithm>

using namespace std;

int dp[101][100001] = { 0, };

int main() {
	int num_stuff, k_of_jun;

	int w[101], v[101];
	cin >> num_stuff >> k_of_jun;

	for (int i = 1; i <= num_stuff; i++) {
		cin >> w[i] >> v[i];
	}

	for (int i = 1; i <= num_stuff; i++) {
		for (int j = 1; j <= k_of_jun; j++) {
			if (w[i] > j)dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
		}
	}
	cout << dp[num_stuff][k_of_jun];
	return 0;
}
