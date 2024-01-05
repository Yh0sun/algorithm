#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	string input;
	vector<string> strs;
	vector<string> prefixes;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> input;
		strs.push_back(input);
	}

	for (int i = 0; i < m; i++) {
		cin >> input;
		prefixes.push_back(input);
	}

	sort(strs.begin(), strs.end());
	sort(prefixes.begin(), prefixes.end());

	int cnt = 0, idx = 0;
	for (int i = 0; i < m; i++) {
		bool flag = false;
		for (int j = idx; j < n; j++) {
			if (strs[j].substr(0, prefixes[i].length()) == prefixes[i]) {
				cnt++;
				idx = j;
				flag = true;
				break;
			}
			if (strs[j] > prefixes[i]) {
				idx = j;
				flag = true;
				break;
			}
		}
		if (!flag)break;
	}
	cout << cnt;
	return 0;
}
