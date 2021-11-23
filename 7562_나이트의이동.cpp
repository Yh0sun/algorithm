#include<iostream>
#include<queue>
using namespace std;

int chessSize;
int visited[301][301];
queue<int> nexti, nextj;
int move(int i, int j);
void reset(int chessSize) {
	for (int a = 0; a < chessSize; a++)
		for (int b = 0; b < chessSize; b++)
			visited[a][b] = 0;
};

int main() {
	int testCase;
	int starti, startj, targeti, targetj;

	cin >> testCase;

	for (int a = 0; a < testCase; a++) {
		cin >> chessSize >> starti >> startj >> targeti >> targetj;
		nexti.push(starti);
		nextj.push(startj);
		visited[starti][startj] = 1;
		while (!nexti.empty()) {
			if (nexti.front() == targeti && nextj.front() == targetj) {
				cout << visited[nexti.front()][nextj.front()] - 1 << endl;
				break;
			}
			move(nexti.front(), nextj.front());
			nexti.pop();
			nextj.pop();
		}
		while (!nexti.empty()) {
			nexti.pop();
			nextj.pop();
		}
		reset(chessSize);
	}
	return 0;
}

int move(int i, int j) {
	int di[8][2] = { {1,2},{2,1},
				{2,-1},{1,-2},
				{-1,-2},{-2,-1},
				{-2,1},{-1,2} };

	for (int k = 0; k < 8; k++) {
		int x = i + di[k][0];
		int y = j + di[k][1];
		if (x >= 0 && x < chessSize && y >= 0 && y < chessSize && visited[x][y] == 0) {
			visited[x][y] = visited[i][j] + 1;
			nexti.push(x);
			nextj.push(y);
		}
	}
	return 0;
}