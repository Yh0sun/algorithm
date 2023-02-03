#include<iostream>
#include <vector>

using namespace std;

int map[101][101] = { 0, };
int dir_y[4] = { 0,-1,0,1 };
int dir_x[4] = { 1,0,-1,0 };

int func(vector<int>& dc, int cnt, int g, int y, int x) {	
	if (cnt == 0) {
		map[y][x] = 1;
		y += dir_y[dc[0]];
		x += dir_x[dc[0]];
		if (0 <= x && x <= 100 && 0 <= y && y <= 100) map[y][x] = 1;
	}

	if (cnt == g) return 0;

	int d;
	for (int i = dc.size() - 1; i > -1; i--) {
		d = dc[i] + 1;
		if (d > 3)d = 0;
		if (d < 0)d = 3;
		dc.push_back(d);

		y += dir_y[d];
		x += dir_x[d];

		if (0 <= x && x <= 100 && 0 <= y && y <= 100) map[y][x] = 1;
	}
	return func(dc, cnt + 1, g, y, x);
}

int main() {
	int num, ans = 0;
	int x, y, d, g;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> x >> y >> d >> g;
		
		vector<int> dir_collection;
		dir_collection.push_back(d);
		
		func(dir_collection, 0, g, y, x);
	}

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == 1)ans++;
		}
	}

	cout << ans;
	return 0;
}