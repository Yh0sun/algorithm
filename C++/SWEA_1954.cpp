#include<iostream>
using namespace std;

void dfs(int a, int b, int c, int (& ht)[10][10], int n);

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int history[10][10] = { 0, };
		int num;

		cin >> num;

		dfs(0, 0, 1, history, num);
		cout << "#" << test_case << endl;
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				cout << history[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
void dfs(int a, int b, int c, int (& ht)[10][10], int n) {

	int y[4] = { 0,1,0,-1 };
	int x[4] = { 1,0,-1,0 };

	ht[a][b] = c;

	for (int i = 0; i < 4; i++) {
		int ny = y[i] + a;
		int nx = x[i] + b;

		if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
			if (ht[ny][nx] == 0) {
				dfs(ny, nx, c + 1, ht, n);
			}
		}
	}
}
