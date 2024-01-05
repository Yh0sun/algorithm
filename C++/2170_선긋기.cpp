#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, x, y;
	cin >> n;
	
	vector<pair<int, int>> line;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		line.push_back({ x,y });
	}

	sort(line.begin(), line.end());

	int min_x = line[0].first;
	int max_y = line[0].second;
	int next_x, next_y;
	int ans = 0;

	for (int i = 1; i < n; i++) {
		next_x = line[i].first;
		next_y = line[i].second;

		if (next_x <= max_y)max_y = max(max_y, next_y);
		else {
			ans += max_y - min_x;
			min_x = next_x;
			max_y = next_y;
		}
	}
	ans += max_y - min_x;
	cout << ans;

	return 0;
}