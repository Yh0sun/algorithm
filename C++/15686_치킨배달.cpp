#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int cnt = 0;
vector<pair<int, int>> chicken;
vector<pair<int, int>> chickenM;
int map[50][50] = { 0, };
int copyMap[50][50] = { 0, };
int min_value = 100000000;

void pickM(int a);
int minDistance();
int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)chicken.push_back(make_pair(i, j));
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			copyMap[i][j] = map[i][j];
			if(map[i][j] == 2)copyMap[i][j] = 0;
		}
	}

	pickM(0);
	cout << min_value;

	return 0;
}
void pickM(int a) {

	for (int i = a; i < chicken.size(); i++) {
		copyMap[chicken[i].first][chicken[i].second] = 2;
		chickenM.push_back(chicken[i]);

		if (chickenM.size() == M) min_value = min(minDistance(), min_value);
		else pickM(i + 1);
		
		copyMap[chicken[i].first][chicken[i].second] = 0;
		chickenM.pop_back();
	}
}
int minDistance() {
	int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
	int visited[50][50] = { 0, };
	int dis = 0;
	queue<pair<int, int>> que;

	for (int i = 0; i < chickenM.size(); i++) {
		que.push(chickenM[i]);
		visited[chickenM[i].first][chickenM[i].second] = 1;
	}
	while (!que.empty()) {
		pair<int, int> curr = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {

			int nx = curr.first + dir[i][0];
			int ny = curr.second + dir[i][1];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (visited[nx][ny] == 0) {
					que.push(make_pair(nx, ny));
					visited[nx][ny] = visited[curr.first][curr.second] + 1;
					if (map[nx][ny] == 1) {
						dis += visited[nx][ny] - 1;
					}
				}
			}
		}
	}
	return dis;
}
