#include <iostream>
using namespace std;
char sheep[100][100];
int visited[100][100];
int heigh, width;

bool SheepGroup(int j, int k);
void reset() {
	for (int i = 0; i < heigh; i++) {
		for (int j = 0; j < width; j++) {
			sheep[i][j] = '0';
			visited[i][j] = 0;
		}
	}
};

int main() {
	int testcase;
	int sheepgroup = 0;

	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		cin >> heigh >> width;

		for (int a = 0; a < heigh; a++) {
			for (int b = 0; b < width; b++) {
				cin >> sheep[a][b];
			}
		}

		for (int j = 0; j < heigh; j++)
			for (int k = 0; k < width; k++) {
				if (SheepGroup(j, k))sheepgroup++;
			}

		cout << sheepgroup << endl;
		sheepgroup = 0;
		reset();
	}
	return 0;
}

bool SheepGroup(int j, int k) {

	int plus[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
	int nextJ, nextK;
	bool isItGroup = false;

	if (sheep[j][k] == '#' && visited[j][k] != 1) {
		visited[j][k] = 1;
		isItGroup = true;
		for (int q = 0; q < 4; q++) {
			nextJ = j + plus[q][0];
			nextK = k + plus[q][1];

			if (nextJ >= 0 && nextJ < heigh && nextK >= 0 && nextK < width) {
				SheepGroup(nextJ, nextK);
			}
			else continue;
		}
	}
	return isItGroup;
}