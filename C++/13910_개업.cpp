#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;

int mdp[10001] = { 0, };

int main() {
	int goal, wokNum;
	
	vector<int> size;

	cin >> goal >> wokNum;

	for (int i = 0; i < wokNum; i++) {
		int tmp;
		cin >> tmp;
		size.push_back(tmp);
	}

	for (int i = 0; i < wokNum - 1; i++) {
		for (int j = i + 1; j < wokNum; j++) {
			size.push_back(size[i] + size[j]);
		}
	}

	vector<vector<int>> dp(goal + 1, vector<int>(size.size()));

	for (int i = 0; i <= goal; i++) {
		for (int j = 0; j < size.size(); j++) {
			if (i - size[j] >= 0) {
				dp[i][j] = mdp[i - size[j]] + 1;
			}
			else {
				dp[i][j] = 10000;
			}

			if (i == size[j]) dp[i][j] = 1;
		}
		mdp[i] = *min_element(dp[i].begin(), dp[i].end());
	}

	if (mdp[goal] >= 10000) cout << -1;
	else cout << mdp[goal];

	return 0;
}