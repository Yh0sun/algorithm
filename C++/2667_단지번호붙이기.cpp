#include<iostream>
#include<algorithm>
using namespace std;

int num, mapSize;
int apartMap[26][26] = { 0, };
int visited[26][26] = { 0, };
int apart(int i, int j);

int main() {
	int count = 0;
	int houseNum[675];
	
	cin >> mapSize;

	for (int i = 0; i < mapSize; i++)
		for (int j = 0; j < mapSize; j++)
			scanf_s("%1d", &apartMap[i][j]);
		
	for (int i = 0; i < mapSize; i++)
		for (int j = 0; j < mapSize; j++) {
			if (apartMap[i][j] != 0 && visited[i][j] == 0) {
				houseNum[count] = apart(i, j);
				count++;
			}
			num = 0;
		}

	sort(houseNum, houseNum + count);
	cout << count << endl;

	for (int z = 0; z < count; z++)
		cout << houseNum[z] << endl;
	
	return 0;
}
int apart(int i, int j) {
	int direction[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

	visited[i][j] = 1;
	num ++;
	for (int k = 0; k < 4; k++) {
		int x = i + direction[k][0];
		int y = j + direction[k][1];
		if (x >= 0 && x < mapSize && y >= 0 && y < mapSize) {
			if (apartMap[x][y] == 1 && visited[x][y] == 0)apart(x, y);
		}
	}
	return num;
}