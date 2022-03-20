#include <iostream>
using namespace std;

int main() {

	int N, K;
	long long dp[202][202] = { 0, };

	cin >> N >> K;

	for (int j = 0; j <= N + 1; j++) {
		dp[2][j] = j;
	}

	for (int i = 3; i < K + 1; i++) {
		for (int j = 1; j <= N + 1; j++) {
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
			dp[i][j] %= 1000000000;
		}
	}

	if (K == 1)cout << "1";
	else cout << dp[K][N + 1];

	return 0;
}
