/*
	!!!!! 100x100 dfs터짐 !!!!!!!
*/

#include <iostream>
#include <queue>
using namespace std;

struct Pos
{
	int x;
	int y;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int map[100][100] = { 0, };
	int visited[100][100] = { 0, };
	int mx[4] = { 0,1,0,-1 };
	int my[4] = { 1,0,-1,0 };

	Pos sword_p = { -1,-1 };
	int n, m, t, ans;
	cin >> n >> m >> t;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	queue<Pos> que;
	que.push({ 0,0 });
	visited[0][0] = 1;

	while (!que.empty()) {
		int cur_x = que.front().x;
		int cur_y = que.front().y;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur_x + mx[i];
			int ny = cur_y + my[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (visited[nx][ny] != 0)continue;
				if (map[nx][ny] == 1)continue;
				if (map[nx][ny] == 2)sword_p = { nx,ny };

				visited[nx][ny] = visited[cur_x][cur_y] + 1;
				que.push({ nx,ny });
			}
		}
	}

	if (visited[n - 1][m - 1] == 0 && sword_p.x == -1 && sword_p.y == -1) {
		cout << "Fail";
		return 0;
	}
	else if (visited[n - 1][m - 1] == 0)ans = visited[sword_p.x][sword_p.y] - 1 + (n - 1 - sword_p.x) + (m - 1 - sword_p.y);
	else if (visited[n - 1][m - 1] - 1 > visited[sword_p.x][sword_p.y] - 1 + (n - 1 - sword_p.x) + (m - 1 - sword_p.y))ans = visited[sword_p.x][sword_p.y] - 1 + (n - 1 - sword_p.x) + (m - 1 - sword_p.y);
	else ans = visited[n - 1][m - 1] - 1;

	if (ans > t)cout << "Fail";
	else cout << ans;
	return 0;
}