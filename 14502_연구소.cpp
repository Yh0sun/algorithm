#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct coordinate
{
	int x;
	int y;
public:
	coordinate() {
		x = 0;
		y = 0;
	}
	coordinate(int a, int b) {
		x = a;
		y = b;
	}
};

coordinate threeWall[3];
int minNumInfection = 65, cnt = -1;
int N, M, lab[8][8];

void wall(int a,int b, int c);
int infection();
bool notThreeWall(int a, int b);

int main() {
	
	int wallNum = 0, result = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> lab[i][j];
			if (lab[i][j] == 1)wallNum++;
		}
	}

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
				threeWall[cnt] = coordinate(i, j);
				if (cnt < 2) {
					if (j + 1 == M) wall(i + 1, 0, cnt);
					else wall(i, j + 1, cnt);
				}
				else {
					minNumInfection = min(minNumInfection, infection());
				}
			}
		}
	}
}

int infection() {
	int infectionChart[8][8] = { 0, };
	int drt[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
	int infection = 0;
	queue<coordinate> que;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (lab[i][j] == 2&&infectionChart[i][j]!=2) {
			
				que.push(coordinate(i, j));
				infectionChart[i][j] = 2;

				while (!que.empty()) {

					coordinate curr = que.front();
					infection++;

					for (int k = 0; k < 4; k++) {
						int Xnext = curr.x + drt[k][0];
						int Ynext = curr.y + drt[k][1];
						if (Xnext >= 0 && Xnext < N && Ynext >= 0 && Ynext < M) {
							if (infectionChart[Xnext][Ynext] != 2 && lab[Xnext][Ynext] != 1 && notThreeWall(Xnext, Ynext)) {
								infectionChart[Xnext][Ynext] = 2;
								que.push(coordinate(Xnext, Ynext));
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

bool notThreeWall(int a, int b) {
	
	for (int i = 0; i < 3; i++) 
		if (threeWall[i].x== a&&threeWall[i].y==b)return false;
	
	return true;
}
