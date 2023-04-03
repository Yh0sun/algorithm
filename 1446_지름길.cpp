#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, D, start, end, val;
	cin >> N >> D;

	priority_queue<pair<int,int>> pq;
	map<int, int> table;
	multimap<int, pair<int, int>> graph;
	table[D] = 10001;

	for (int i = 0; i < N; i++) {
		cin >> start >> end >> val;

		if (end > D)continue;
		graph.emplace(start, make_pair( end,val ));
		table[start] = 10001;
		table[end] = 10001;
	}

	map<int, int> ::iterator itr;
	int s = 0;
	for (itr = table.begin(); itr != table.end(); itr++) {
		int e = itr->first;
		graph.emplace(s, make_pair(e, e - s));
		s = e;
	}

	pq.push({ 0,0 });
	table[0] = 0;
	while (!pq.empty()) {
		int val = -pq.top().first;
		int end = pq.top().second;
		pq.pop();

		if (table[end] < val)continue;

		map<int, pair<int, int>> ::iterator iter;
		for (iter = graph.lower_bound(end); iter != graph.upper_bound(end); iter++) {
			pair<int, int> g = iter->second;
			int nval = g.second;
			int nend = g.first;

			if (table[nend] <= nval + table[end])continue;
			table[nend] = table[end] + nval;
			pq.push({ -table[nend],nend });
		}
	}
	cout << table[D];
	return 0;
}
