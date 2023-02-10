#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int Log = 0;

int dfs(int n, vector<vector<int>>& adj, vector<int>& depth, vector<vector<int>>& parent) {

	for (int i = 0; i < adj[n].size(); i++) {
		int next = adj[n][i];
		if (depth[next] != -1)continue;

		parent[next].push_back(n);
		depth[next] = depth[n] + 1;
		dfs(next, adj, depth, parent);
	}
	return 0;
}
int make_parent(vector<vector<int>>& parent) {
	for (int i = 1; i <= Log; i++) {
		for (int j = 0; j < parent.size(); j++) {
			int p = parent[j][i - 1];
			if (p == 0)parent[j].push_back(0);
			else parent[j].push_back(parent[p][i - 1]);
		}
	}
	return 0;
}
int LCA(int s, int e, vector<int>& depth, vector<vector<int>>& parent) {

	if (depth[s] != depth[e]) {
		if (depth[s] < depth[e])swap(s, e);
		for (int i = Log; i >= 0; i--) {
			if (depth[parent[s][i]] > depth[e])s = parent[s][i];
		}
		s = parent[s][0];
	}

	if (s == e)return s;

	for (int i = Log; i >= 0; i--) {
		if (parent[s][i] != parent[e][i]) {
			s = parent[s][i];
			e = parent[e][i];
		}
	}
	return parent[s][0];
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m, u, v;
	cin >> n;

	vector<vector<int>> parent(n + 1, vector<int>());
	vector<vector<int>> adj(n + 1, vector<int>());
	vector<int> depth(n + 1,-1);
	Log = (int)log2(n);

	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	adj[0].push_back(1);
	parent[0].push_back(0);
	dfs(0, adj, depth, parent);
	make_parent(parent);

	cin >> m;
	while (m--) {
		cin >> u >> v;
		cout << LCA(u, v, depth, parent) << "\n";
	}
	return 0;
}
