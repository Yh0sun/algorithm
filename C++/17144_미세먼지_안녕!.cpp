#include <iostream>
#include <vector>
using namespace std;

int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };

vector<pair<int, int>> airCleaner;
bool isAirCleaner(int x, int y) {
	for (int i = 0; i < airCleaner.size(); i++) 
		if (x == airCleaner[i].first && y == airCleaner[i].second) 
			return true;
	return false;
}
int main() {
	int result = 0;
	int R, C, T;
	
	cin >> R >> C >> T;
	vector<vector<int>> room(R, vector<int>(C));

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> room[i][j];
			if (room[i][j] == -1)airCleaner.push_back({ i,j });
		}
	}

	while (T--) {
		vector<vector<int>> after(R, vector<int>(C));
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (room[i][j] > 0) {
					int cnt = 0;
					for (int k = 0; k < 4; k++) {
						int x = i + dx[k];
						int y = j + dy[k];
						if (x >= 0 && x < R && y >= 0 && y < C && !isAirCleaner(x, y)) {
							after[x][y] += room[i][j] / 5;
							cnt++;
						}
					}
					after[i][j] += room[i][j] - room[i][j] / 5 * cnt;
				}
			}
		}
		room = after;
		for (int i = 0; i < 2; i++) {
			int index = 0, beforeVal = 0;
			int ac_x = airCleaner[i].first;
			int ac_y = airCleaner[i].second;

			do {
				ac_x += dx[index];
				ac_y += dy[index];
				if (ac_x < 0 || ac_x >= R || ac_y < 0 || ac_y >= C) {
					ac_x -= dx[index];
					ac_y -= dy[index];

					++index;
					if (i == 1)index = (index + 2) % 4;
			
					continue;
				}
			/*	int tmp = room[ac_x][ac_y];
				room[ac_x][ac_y] = beforeVal;
				beforeVal = tmp; */
				swap(room[ac_x][ac_y], beforeVal);
			} while (!isAirCleaner(ac_x, ac_y));
			
			room[ac_x][ac_y] = 0;
		}		
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			result += room[i][j];
		}
	}
	cout << result;
	return 0;
}
