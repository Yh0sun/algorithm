#include <iostream>
#include <vector>
using namespace std;

int move_x[3] = { 0,1,1 };
int move_y[3] = { 1,1,0 };
vector<vector<int>>dir = { {0,1},{0,1,2},{1,2} };
int N;

bool possible_way(int x, int y, int d, vector<vector<int>>& map) {

	if (d == 1) {
		if (x - 1 >= 0 && map[x - 1][y] == 1)return false;
		if (y - 1 >= 0 && map[x][y - 1] == 1)return false;
	}
	if (map[x][y] == 1)return false;
	return true;
}
int func(int cur_x, int cur_y, int cur_dir, vector<vector<int>>& map, vector<vector<int>>& visited, int& ans) {

	//cout << cur_x << " " << cur_y << "\n";
	if (cur_x == N - 1 && cur_y == N - 1) {
		ans++;
		//cout << ans << "\n";
		return 0;
	}

	for (int i = 0; i < dir[cur_dir].size(); i++) {
		int next_dir = dir[cur_dir][i];
		int next_x = cur_x + move_x[next_dir];
		int next_y = cur_y + move_y[next_dir];

		if (0 <= next_x && next_x < N && 0 <= next_y && next_y < N) {
			if (visited[next_x][next_y] == 1)continue;
			if (!possible_way(next_x, next_y, next_dir, map))continue;
			visited[next_x][next_y] = 1;
			func(next_x, next_y, next_dir, map, visited, ans);
			visited[next_x][next_y] = 0;
		}
	}
	return 0;
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int ans = 0;
	vector<vector<int>> map(N, vector<int>(N));
	vector<vector<int>> visited(N, vector<int>(N));
	visited[0][0] = 1;
	visited[0][1] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	func(0, 1, 0, map, visited, ans);
	cout << ans;
	return 0;
}