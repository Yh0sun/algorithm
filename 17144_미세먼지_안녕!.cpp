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
					//printf("%d %d\n", i, j);
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
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				printf("%d ", room[i][j]);
			}
			printf("\n");
		}

		int index1 = 0, index2 = 0, beforeVal1 = 0, beforeVal2 = 0;
		int ac_x1 = airCleaner[0].first;
		int ac_y1 = airCleaner[0].second;
		int ac_x2 = airCleaner[1].first;
		int ac_y2 = airCleaner[1].second;
		//printf("ac1 --- %d %d\n", ac_x1, ac_y1);
		//printf("ac2 --- %d %d\n", ac_x2, ac_y2);
		do {
			room[ac_x1][ac_y1] = beforeVal1;
			room[ac_x2][ac_y2] = beforeVal2;

			ac_x1 += dx[index1];
			ac_y1 += dy[index1];
			//printf("1 --- %d %d\n", ac_x1, ac_y1);

			ac_x2 += dx[index2];
			ac_y2 += dy[index2];
			//printf("2 --- %d %d\n", ac_x2, ac_y2);
			if (ac_x1 < 0 || ac_x1 >= R || ac_y1 < 0 || ac_y1 >= C) {
				printf("dddd\n");
				ac_x1 -= dx[index1];
				ac_y1 -= dy[index1];

				ac_x2 -= dx[index2];
				ac_y2 -= dy[index2];

				index2 = ++index1;
				if (index1 == 1)index2 = 3;
				if (index1 == 3)index2 = 1;

				continue;
			}

			beforeVal1 = room[ac_x1][ac_y1];
			beforeVal2 = room[ac_x2][ac_y2];
		} while (!isAirCleaner(ac_x1, ac_y1));

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				printf("%d ", room[i][j]);
			}
			printf("\n");
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
