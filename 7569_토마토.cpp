#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int tomato[100][100][100];
int m, n, h;

class poz {
private:
	int z;
	int x;
	int y;
public:
	poz() {
		z = 0;
		x = 0;
		y = 0;
	}
	poz(int a, int b, int c) {
		z = a;
		x = b;
		y = c;
	}
	poz(const poz& p) {
		z = p.z;
		x = p.x;
		y = p.y;
	}
	void push(int a, int b, int c) {
		z = a;
		x = b;
		y = c;
	}
	void add(int a, int b, int c) {
		z += a;
		x += b;
		y += c;
	}
	bool available() {
		if (z >= 0 && x >= 0 && y >= 0 && z < h && x < n && y < m)
			return true;
		else return false;
	}
	bool notReady() {
		if (tomato[z][x][y] == 0) {
			return true;
		}
		else { return false; }
	}
	void getReady(poz& p) {
		tomato[z][x][y] = tomato[p.z][p.x][p.y] + 1;
	}
	poz operator + (poz& p) {
		return poz(z + p.z, x + p.x, y + p.y);
	}
};

int main() {

	poz p[6] = { {0,1,0},{0, -1, 0},{0, 0, 1},{0, 0, -1},{1, 0, 0}, {-1, 0, 0} };
	queue <poz> bfs;

	cin >> m >> n >> h;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 1) {
					bfs.push(poz(i, j, k));
				}
			}
		}

	while (!bfs.empty()) {
		for (int i = 0; i < 6; i++) {
			poz nextT = bfs.front() + p[i];
			if (nextT.available() && nextT.notReady()) {
				bfs.push(nextT);
				nextT.getReady(bfs.front());
			}
		}
		bfs.pop();
	}

	int re = 0;
	bool sw = false;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (tomato[i][j][k] == 0) {
					sw = true;
				}
				re = max(re, tomato[i][j][k]);
			}
		}
	}

	if (sw)cout << "-1";
	else cout << re - 1;

	return 0;
}
