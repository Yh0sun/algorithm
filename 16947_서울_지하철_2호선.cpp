#include <iostream>
#include <vector>

using namespace std;

int dfs(int start, int cur, vector<vector<int>>& stt, vector<int>& visited) {
	for (int i = 0; i < stt[cur].size(); i++) {
		int next = stt[cur][i];

		if (visited[next] != 0) {
			if (visited[next] == visited[cur] - 1)continue;
			if (stt[next].size() > 2)return visited[next] - 1;
			if (next == start)return 0;
			continue;
		}

		visited[next] = visited[cur] + 1;
		int tmp = dfs(start, next, stt, visited);
		if (tmp != -1)return tmp;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, station1, station2;
	cin >> n;

	vector<vector<int>> stt(n + 1, vector<int>());
	vector<int> dist(n + 1);

	for (int i = 0; i < n; i++) {
		cin >> station1 >> station2;

		stt[station1].push_back(station2);
		stt[station2].push_back(station1);
	}

	for (int i = 1; i <= n; i++) {
		vector<int> visited(n + 1);
		visited[i] = 1;
		cout << dfs(i, i, stt, visited) << " ";
	}
	return 0;
}