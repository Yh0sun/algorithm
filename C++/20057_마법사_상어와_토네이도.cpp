#include <iostream>
#include <vector>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int blow_index[4][10][3] = {
	{{-1,-1,1},{-1,1,1},{0,-2,2},{0,2,2},{0,-1,7},{0,1,7},{1,-1,10},{1,1,10},{2,0,5},{1,0,0}},
	{{-1,-1,1},{1,-1,1},{-2,0,2},{2,0,2},{-1,0,7},{1,0,7},{-1,1,10},{1,1,10},{0,2,5},{0,1,0} },
	{{1,-1,1},{1,1,1},{0,-2,2},{0,2,2},{0,-1,7},{0,1,7},{-1,-1,10},{-1,1,10},{-2,0,5},{-1,0,0}},
	{{-1,1,1},{1,1,1},{-2,0,2},{2,0,2},{-1,0,7},{1,0,7},{-1,-1,10},{1,-1,10},{0,-2,5},{0,-1,0} }
};

double N;
vector<vector<int>> map;
int out_sand = 0;
int visited[500][500] = { 0, };
int dfs(int x, int y, int cha);
void blow(int  x, int y, int d);

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		vector<int> vec;
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;
			vec.push_back(tmp);
		}
		map.push_back(vec);
	}

	int start = (int)N / 2;
	int start_x = start, start_y = start - 1;
	visited[start][start] = 1;

	for (int i = 1; i < N / 2; i++) {

		blow(start_x, start_y, 3);

		dfs(start_x, start_y, i);
		start_x -= 1;
		start_y -= 1;
	}

	cout << out_sand;
	return 0;
}
int dfs(int x, int y, int cha) {

	int min = N / 2 - cha;
	int max = N / 2 + cha;

	visited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if (next_x >= min && next_x <= max && next_y >= min && next_y <= max) {
			if (visited[next_x][next_y] == 0) {
				blow(next_x, next_y, i);
				dfs(next_x, next_y, cha);
			}

		}
	}
	return 0;
}
void blow(int x, int y, int d) {

	int sand = map[x][y];
	int move_sand = 0;
	int out = 0;

	map[x][y] = 0;

	for (int i = 0; i < 10; i++) {
		int _x = x + blow_index[d][i][0];
		int _y = y + blow_index[d][i][1];
		if (_x >= 0 && _x < N && _y >= 0 && _y < N) {
			if (i == 9)map[_x][_y] += (sand - move_sand - out);
			else {
				map[_x][_y] += sand * blow_index[d][i][2] / 100;
				move_sand += sand * blow_index[d][i][2] / 100;
			}
		}
		else {
			if (i == 9)out += (sand - move_sand - out);
			else out += sand * blow_index[d][i][2] / 100;
		}
	}
	out_sand += out;
}
