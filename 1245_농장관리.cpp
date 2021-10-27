#include<iostream>
using namespace std;
int mountain[100][70];
int vistedSpot[100][70];
int peakHistory[100][70];
int n, m;
int search(int i, int j);
void remove(int x, int y, int m);
void reset() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			vistedSpot[i][j] = 0;
		}
	}
};

int main() {
	int count = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mountain[i][j];
		}
	}

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {

			if (peakHistory[x][y] != 1) {

				peakHistory[x][y] = 1;

				if (search(x, y) == 1)count++;
				else remove(x, y, mountain[x][y]);
		
			}
			else continue;
			reset();
		}
	}
	cout << count;

	return 0;
}

int search(int i, int j) {
	int drt[8][2] = { {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1} };
	int nextX, nextY;
	int peak = 1;
	
	for (int k = 0; k < 8; k++) {

		nextX = i + drt[k][0];
		nextY = j + drt[k][1];

		if (0 <= nextX && nextX < n && 0 <= nextY && nextY < m) {
			if (mountain[i][j] > mountain[nextX][nextY] && vistedSpot[nextX][nextY] == 0) {
				vistedSpot[nextX][nextY] = 1;
			}
			else if (mountain[i][j] == mountain[nextX][nextY] && vistedSpot[nextX][nextY] == 0) {
				vistedSpot[nextX][nextY] = 1;
				peakHistory[nextX][nextY] = 1;
				peak = search(nextX, nextY);
				if (peak == 0)break;
			}
			else if (mountain[i][j] < mountain[nextX][nextY] && vistedSpot[nextX][nextY] == 0) {
				peak = 0;
				vistedSpot[nextX][nextY] = 1;
				break;
			}
			else {
				continue;
			}
		}
	}
	return peak;
}

void remove(int x, int y,int m) {
	int drt[8][2] = { {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1} };
	int nextX, nextY;

	for (int k = 0; k < 8; k++) {

		nextX = x + drt[k][0];
		nextY = y + drt[k][1];
		if (vistedSpot[x][y] != 0) break;

		if (0 <= nextX && nextX < n && 0 <= nextY && nextY < m) {

			if (mountain[x][y] == m ){
				peakHistory[x][y] = 0;
				vistedSpot[x][y] = 1;
				remove(nextX, nextY, m);
			}
		}
	}
	return;
}
