#include <iostream>
#include <queue>

using namespace std;

int N, M;
int sea[50][50];

int findDistance(int i, int j);
int main() {

	int safe_distance = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> sea[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (sea[i][j] != 1) {
				safe_distance = max(safe_distance, findDistance(i, j));
			}
		}
	}
	cout << safe_distance;
	return 0;
}

int findDistance(int i, int j) {

	int dir[8][2] = { {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1} };
	int visited[50][50] = { 0, };
	queue <pair<int, int>> bfs;

	bfs.push(make_pair(i, j));
	visited[i][j] = 1;
	while (!bfs.empty()) {
		pair<int, int> curr = bfs.front();
		bfs.pop();
		for (int k = 0; k < 8; k++) {
			int n_i = curr.first + dir[k][0];
			int n_j = curr.second + dir[k][1];
			if (n_i >= 0 && n_i < N && n_j >= 0 && n_j < M) {
				if (visited[n_i][n_j] == 0) {
					bfs.push(make_pair(n_i, n_j));
					visited[n_i][n_j] = visited[curr.first][curr.second] + 1;

					if (sea[n_i][n_j] == 1) {
						return visited[n_i][n_j] - 1;
					}
				}
			}
		}
	}
}
