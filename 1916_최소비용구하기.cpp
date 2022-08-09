#include <iostream>
#include <vector>
using namespace std;

int main() {
	int city, bus;
	cin >> city >> bus;

	vector<vector<pair<int, int>>> table(city + 1, vector < pair<int, int>>());
	vector<int> dp(city + 1);
	for (int i = 0; i < bus; i++) {
		int _start, _end, val;
		cin >> _start >> _end >> val;
		table[_start].push_back({ _end,val });
	}
	int start, end;
	cin >> start >> end;

	while (true) {
		for (int i = 0; i < table[start].size(); i++) {
			pair<int, int> _bus;
			dp[_bus.first] = _bus.second;
		}
	}
	return 0;
}
