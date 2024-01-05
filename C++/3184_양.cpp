#include<iostream>
using namespace std;
char field[250][250];
int r, c, sheep = 0, wolf = 0;
int visited[250][250];
void fence(int i, int j);

int main() {
	int leftSheep = 0, leftWolf = 0;
	cin >> r >> c;

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> field[i][j];

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (visited[i][j] == 0 && field[i][j] != '#') {
				fence(i, j);
				if (sheep > wolf) leftSheep += sheep;
				else leftWolf += wolf;
			}
			sheep = 0;
			wolf = 0;
		}
	}
	cout << leftSheep << " " << leftWolf;
	return 0;
}

void fence(int i, int j) {
	int arr[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

	if (field[i][j] == 'o')
		sheep++;

	if (field[i][j] == 'v')
		wolf++;

	visited[i][j] = 1;

	for (int k = 0; k < 4; k++) {
		int x = i + arr[k][0];
		int y = j + arr[k][1];
		if (x >= 0 && x < r && y >= 0 && y < c) {
			if (field[x][y] != '#' && visited[x][y] == 0)fence(x, y);
			else continue;
		}
	}
}