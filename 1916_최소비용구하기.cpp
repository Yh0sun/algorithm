#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct comp
{
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.second > b.second)
			return true;
		else return false;
	}
};

int main() {

	int city, bus;
	cin >> city >> bus;

	vector<vector<pair<int, int>>> table(city + 1, vector < pair<int, int>>());
	priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
	vector<int> min_cost(city + 1,2000000000);

	for (int i = 0; i < bus; i++) {
		int _start, _end, val;
		cin >> _start >> _end >> val;
		table[_start].push_back({ _end,val });
	}

	int start, end;
	cin >> start >> end;

	min_cost[start] = 0;
	pq.push({ start,0 });

	while (!pq.empty()) {
		int next = pq.top().first;
		int val = pq.top().second;
		pq.pop();

		if (min_cost[next] < val)continue;

		for (int i = 0; i < table[next].size(); i++) {
			int ct = table[next][i].first;
			int cost = table[next][i].second;
			if (min_cost[ct] > val + cost) {
				min_cost[ct] = val + cost;
				pq.push({ ct,min_cost[ct] });
			}
		}
	}

	cout << min_cost[end];
	return 0;
}
