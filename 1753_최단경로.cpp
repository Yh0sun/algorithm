#include <iostream>
#include <vector>
#include <queue>

#define INF 200001

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int v, e, start;
	cin >> v >> e >> start;

	vector<vector<pair<int, int>>> graph(v + 1, vector<pair<int, int>>());
	priority_queue<pair<int, int>> pq;
	vector<int> table(v + 1, INF);
	for (int i = 0; i < e; i++) {
		int from, to, val;
		cin >> from >> to >> val;
		graph[from].push_back({ -val,to });
	}

	pq.push({ 0,start });
	table[start] = 0;

	while (!pq.empty()) {
		int d = -pq.top().first;
		int next = pq.top().second;
		pq.pop();

		if (table[next] < d)continue;

		for (int i = 0; i < graph[next].size(); i++) {
			int _val = -graph[next][i].first;
			int _to = graph[next][i].second;
			if (table[_to] > d + _val) {
				table[_to] = d + _val;
        pq.push({ -(d + _val),_to });
			}
		}
	}

	for (int i = 1; i < table.size(); i++) {
		if (table[i] == INF)printf("INF\n");
		else printf("%d\n", table[i]);
	}
  
	return 0;
}
