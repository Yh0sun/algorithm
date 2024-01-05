#include <iostream>

using namespace std;

int goal, city;
int cost[21], sp[21];
int dp[1001][21] = { 0, };

void min_to_dp0(int i) {

	int minn = 10000000;

	for (int j = 1; j <= city; j++) {
		if (dp[i][j] < minn) {
			minn = dp[i][j];
		}
		else continue;
	}
	
	dp[i][0] = minn;
}

int main() {

	cin >> goal >> city;

	for (int i = 1; i <= city; i++) {
		cin >> cost[i] >> sp[i];
	}

	for (int i = 1; i <= goal; i++) {
		for (int j = 1; j <= city; j++) {
			if (i < sp[j])dp[i][j] = cost[j];
			else dp[i][j] = dp[i - sp[j]][0] + cost[j];
		}
		min_to_dp0(i);
	}

	cout << dp[goal][0];
	return 0;
}