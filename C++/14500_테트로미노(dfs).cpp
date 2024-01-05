#include <iostream>
#include <vector>
using namespace std;

int n, m;
int table[500][500];
int x[4] = { -1,0,1,0 };
int y[4] = { 0,1,0,-1 };
int max_val = -1;

int dfs(int i, int j, int cnt, int sum, vector<vector<int>>& visited);
void fuck_shape(int i, int j);

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> table[i][j];
		}
	}

	vector<vector<int>> visited(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int cnt = 0;
			int sum = 0;

			dfs(i, j, cnt, sum, visited);
			fuck_shape(i, j);
		}
	}

	cout << max_val << endl;
	return 0;
}
int dfs(int i, int j, int cnt, int sum, vector<vector<int>>& visited) {
	
	visited[i][j] = 1;
	sum += table[i][j];
	cnt++;
	if (cnt == 4) {
		if (max_val < sum) max_val = sum;
		visited[i][j] = 0;
		return 0;
	}

	for (int k = 0; k < 4; k++) {
		int next_x = i + x[k];
		int next_y = j + y[k];
		if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m) {
			if (visited[next_x][next_y] == 0) {
				dfs(next_x, next_y, cnt, sum, visited);
			}
		}
	}
	visited[i][j] = 0;
	return 0;
}
void fuck_shape(int i, int j) {

	int sum = 0;

	if (i + 2 < n && j + 1 < m) sum = table[i][j] + table[i + 1][j] + table[i + 2][j] + table[i + 1][j + 1];
	if (max_val < sum) max_val = sum;
	if (i + 2 < n && j - 1 >= 0) sum = table[i][j] + table[i + 1][j] + table[i + 2][j] + table[i + 1][j - 1];
	if (max_val < sum) max_val = sum;
	if (i + 1 < n && j + 2 < m) sum = table[i][j] + table[i][j + 1] + table[i][j + 2] + table[i + 1][j + 1];
	if (max_val < sum) max_val = sum;
	if (i - 1 >= 0 && j + 2 < m) sum = table[i][j] + table[i][j + 1] + table[i][j + 2] + table[i - 1][j + 1];
	if (max_val < sum) max_val = sum;
	
}
