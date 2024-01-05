#include<iostream>
using namespace std;

int main() {
	int leftDay;
	int t[16] = { 0, }, p[16] = { 0, };
	int dp[16][16] = { 0, }, mDp[16] = { 0, };
	
	cin >> leftDay;

	for (int i = 1; i <= leftDay; i++) {
		cin >> t[i] >> p[i];
		dp[i][i + t[i] - 1] = p[i];
	}

	for (int j = 1; j <= leftDay; j++) {
		for (int k = 1; k <= leftDay; k++) {
			dp[k][j] = mDp[k - 1] + dp[k][j];
			if (mDp[j] < dp[k][j])mDp[j] = dp[k][j];
		}
	}
	cout << mDp[leftDay];
	return 0;
}