#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(int root, vector<vector<int>>& v, vector <int>& depth, int& max_depth) {

	queue<int> que;
	que.push(root);
	depth[root] = 1;

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int n = v[cur][i];
			if (depth[n] != 0)continue;

			depth[n] = depth[cur] + 1;
			if (max_depth < depth[n])max_depth = depth[n];
			que.push(n);
		}
	}
	return 0;
}
int LCA(int s, int e, vector<vector<int>>& table, vector<int>& depth) {
	
	if (depth[s] != depth[e]) {
		if (depth[s] < depth[e])swap(s, e);
		for (int i = table[s].size() - 1; i >= 0; i--) {
			if (depth[table[s][i]] > depth[e]) {
				s = table[s][i];
			}
		}
		s = table[s][0];
	}

	if (s == e) return s;

	for (int i = table[s].size() - 1; i >= 0; i--) {
		if (table[s][i] != table[e][i]) {
			s = table[s][i];
			e = table[e][i];
		}
	}
	return table[s][0];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int node_num, node1, node2, root = 0, max_depth = -1;
		cin >> node_num;

		vector<vector<int>> v(node_num + 1, vector<int>());
		vector<int> depth(node_num + 1);
		vector<vector<int>> table(node_num + 1, vector<int>(1));

		for (int i = 0; i < node_num - 1; i++) {
			cin >> node1 >> node2;
			table[node2][0] = node1;
			v[node1].push_back(node2);
		}

		for (int i = 0; i <= node_num; i++) {
			if (table[i][0] == 0)root = i;
		}
		bfs(root, v, depth, max_depth);

		int num = 1;
		for (int i = 1;; i++) {
			num *= 2;
			for (int j = 0; j <= node_num; j++) {
				int prior = table[j][i - 1];
				if (prior == 0) {
					table[j].push_back(0);
					continue;
				}
				table[j].push_back(table[prior][i - 1]);
			}
			if (num > max_depth)break;
		}

		int start, end;
		cin >> start >> end;
		cout << LCA(start, end, table, depth) << "\n";
	}
	return 0;
}