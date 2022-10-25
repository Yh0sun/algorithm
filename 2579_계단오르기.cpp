#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int stair[301] = { 0, }, dp[301] = { 0, };
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> stair[i];
	}

	dp[2] = stair[1];

	for (int i = 3; i <= n + 1; i++) {
		dp[i] = max(dp[i - 3] + stair[i - 2] + stair[i - 1], dp[i - 2] + stair[i - 1]);
	}
	cout << dp[n + 1];
	return 0;
}
