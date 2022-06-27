#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

	int nodeNum;

	cin >> nodeNum;

	vector<vector<int>> line(nodeNum + 1, vector<int> (1));
	vector<int> parent(nodeNum + 1);
	parent[0] = 1;
	parent[1] = 1;

	for (int i = 0; i < nodeNum - 1; i++) {
		int a, b;
		cin >> a >> b;

		line[a].push_back(b);
		line[b].push_back(a);
	}

	queue<int> que;
	que.push(1);
	
	while (!que.empty()) {
		int curr = que.front();
		que.pop();

		for (int i = 0; i < line[curr].size(); i++) {
			int node = line[curr][i];
			if (parent[node] == 0) {
				parent[node] = curr;
				que.push(node);
			}
		}
		
	}

	for (int i = 2; i < parent.size(); i++) {
		cout << parent[i] << endl;
	}
	return 0;
}
