#include <iostream>
using namespace std;

class robot
{public:

	int y = 0, x = 0;
	int dir = 0;

	pair<int, int> next() {
		dir -= 1;
		if (dir < 0)dir = 3;

		if (dir == 0)return make_pair(y - 1, x);
		if (dir == 1)return make_pair(y, x + 1);
		if (dir == 2)return make_pair(y + 1, x);
		if (dir == 3)return make_pair(y, x - 1);
	}
	void back() {
		if (dir == 0) y++;
		if (dir == 1) x--;
		if (dir == 2) y--;
		if (dir == 3) x++;
	}
}ro;

int cleanNum = 0;
int map[52][52] = { 0, };

void cleanUp();
int main() {
	int N, M;
	
	cin >> N >> M >> ro.y >> ro.x >> ro.dir;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	cleanUp();
	cout << cleanNum;

	return 0;
}

void cleanUp() {

	if (map[ro.y][ro.x] == 0) {
		cleanNum++;
		map[ro.y][ro.x] = 2;
	}

	bool move = false;
	int i = 0;
	for (; i < 4; i++) {
		pair<int, int> nt = ro.next();
		if (map[nt.first][nt.second] == 0) {
			ro.y = nt.first;
			ro.x = nt.second;
			cleanUp();
			break;
		}
	}

	if (i == 4) {
		ro.back();
		if (map[ro.y][ro.x] != 1) {
			cleanUp();
		}
	}
}
