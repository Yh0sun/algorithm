#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct position{
	int x;
	int y;
public:
	position(int a, int b) {
		x = a;
		y = b;
	}
};

int row, col, dis;
int maxSucess = 0, cnt = 0;
vector<vector<int>> enemy;

position findEnemy(int n, int s);

int main() {

	cin >> row >> col >> dis;

	vector<vector<int>> input(row, vector<int>(col));
	enemy.resize(1000);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> input[i][j];

	for (int a = 0; a < col - 2; a++) {
		for (int b = a + 1; b < col - 1; b++) {
			for (int c = b + 1; c < col; c++) {

				copy(input.begin(), input.end(), enemy.begin());

				for (int n = 0; n < row; n++) {
					position p_for_a = findEnemy(n, a);
					position p_for_b = findEnemy(n, b);
					position p_for_c = findEnemy(n, c);

					if (p_for_a.x != 15) {
						if (enemy[p_for_a.x][p_for_a.y] == 1) {
							cnt++;
							enemy[p_for_a.x][p_for_a.y] = 0;
						}
					}

					if (p_for_b.x != 15) {
						if (enemy[p_for_b.x][p_for_b.y] == 1) {
							cnt++; 
							enemy[p_for_b.x][p_for_b.y] = 0;
						}
					}

					if (p_for_c.x != 15) {
						if (enemy[p_for_c.x][p_for_c.y] == 1) {
							cnt++; 
							enemy[p_for_c.x][p_for_c.y] = 0;
						}
					}
				}
				maxSucess = max(cnt, maxSucess);
				cnt = 0;
			}
		}
	}
	cout << maxSucess;
	return 0;
}

position findEnemy(int n, int s) {
	int dir[3][2] = { {0,-1},{-1,0},{0,1} };
	int visited[15][15] = { 0, };

	queue<position> que;
	que.push(position(row - 1 - n, s));
	visited[row - 1 - n][s] = 1;

	int kill_x = 15, kill_y = 15;

	while (!que.empty()) {
		position curr = que.front();
		que.pop();
		if (dis >= (abs((row - n) - curr.x) + abs(s - curr.y))) {
			if (enemy[curr.x][curr.y] == 1) {
				kill_x = curr.x;
				kill_y = curr.y;
				break;
			}
			for (int i = 0; i < 3; i++) {
				int next_x = curr.x + dir[i][0];
				int next_y = curr.y + dir[i][1];
				if (next_x >= 0 && next_x < row && next_y >= 0 && next_y < col) {
					if (visited[next_x][next_y] != 1) {
						que.push(position(next_x, next_y));
						visited[next_x][next_y] = 1;
					}
				}
			}
		}
	}
	return position(kill_x, kill_y);
}
