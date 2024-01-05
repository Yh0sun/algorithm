#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int minNumInfection = 65;
int N, M, cnt = 0;
int temp_lab[8][8], lab[8][8];

void wall(int a, int b, int c);
int infection();

int main() {

	int wallNum = 0, result = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> lab[i][j];
			if (lab[i][j] == 1)wallNum++;
		}
	}
	copy(&lab[0][0], &lab[0][0] + 64, &temp_lab[0][0]);
	wall(0, 0, cnt);

	result = N * M - wallNum - 3 - minNumInfection;
	cout << result;

	return 0;
}

void wall(int a, int b, int cnt) {
	cnt++;

	for (int i = a; i < N; i++) {
		int j = 0;
		if (i == a)j = b;
		for (; j < M; j++) {
			if (lab[i][j] == 0) {
				temp_lab[i][j] = 1;
				if (cnt < 3) {
					if (j + 1 == M) wall(i + 1, 0, cnt);
					else wall(i, j + 1, cnt);
				}
				else {
					minNumInfection = min(minNumInfection, infection());
					
				}
				temp_lab[i][j] = 0;
			}
		}
	}
}

int infection() {
	int infectionChart[8][8] = { 0, };
	int drt[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
	int infection = 0;
	queue < pair<int, int>> que;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (lab[i][j] == 2 && infectionChart[i][j] != 2) {

				que.push(make_pair(i, j));
				infectionChart[i][j] = 2;

				while (!que.empty()) {

					infection++;

					for (int k = 0; k < 4; k++) {
						int Xnext = que.front().first + drt[k][0];
						int Ynext = que.front().second + drt[k][1];
						if (Xnext >= 0 && Xnext < N && Ynext >= 0 && Ynext < M) {
							if (infectionChart[Xnext][Ynext] != 2 && temp_lab[Xnext][Ynext] != 1) {
								infectionChart[Xnext][Ynext] = 2;
								que.push(make_pair(Xnext, Ynext));
							}
						}
					}
					que.pop();
				}
			}
		}
	}
	return infection;
}
