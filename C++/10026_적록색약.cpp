#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, cnt = 1;
char chosenColor;
char colors[100][100];
char RGcolors[100][100];
int visited[100][100];
int region[100][100];
int drt[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

void search(int a, int b, char c[][100]);

int main() {
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			cin >> colors[i][j];
			
			if (colors[i][j] == 'G') RGcolors[i][j] = 'R';
			else RGcolors[i][j] = colors[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (region[i][j] == 0) {
				chosenColor = colors[i][j];
				search(i, j, colors);
				memset(visited, 0, sizeof(visited));
				cnt++;
			}
		}
	}

	cout << cnt - 1 << " ";
	cnt = 1;
	memset(region, 0, sizeof(region));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (region[i][j] == 0) {
				chosenColor = RGcolors[i][j];
				search(i, j, RGcolors);
				memset(visited, 0, sizeof(visited));
				cnt++;
			}
		}
	}

	cout << cnt - 1;

	return 0;
}

void search(int a, int b, char c[][100]) {

	visited[a][b] = 1;
	region[a][b] = cnt;

	for (int i = 0; i < 4; i++) {
		int nextX = b + drt[i][1];
		int nextY = a + drt[i][0];
		if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < n) {
			if (visited[nextY][nextX] == 0 && c[nextY][nextX] == chosenColor)
				search(nextY, nextX, c);
		}
	}
}