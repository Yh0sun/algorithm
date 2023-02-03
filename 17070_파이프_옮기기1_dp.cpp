#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<vector<int>> map(N + 1, vector<int>(N + 1));
	vector<vector<int>> visited(N + 1, vector<int>(N + 1));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 2; i <= N; i++) {
		if (map[1][i] == 1)break;
		visited[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 3; j <= N; j++) {
			if (map[i][j] == 1)continue;

			for (int k = j; k > 0; k--) {
				if (map[i][k] == 1)break;
				if (map[i][k - 1] == 1)break;
				if (map[i - 1][k - 1] == 1)continue;
				if (map[i - 1][k] == 1)continue;

				visited[i][j] += visited[i - 1][k - 1];
			}
			for (int k = i - 1; k > 0; k--) {
				if (map[k][j] == 1)break;
				if (map[k - 1][j] == 1)break;
				if (map[k - 1][j - 1] == 1)continue;
				if (map[k][j - 1] == 1)continue;

				visited[i][j] += visited[k - 1][j - 1];
			}
		}
	}
	cout << visited[N][N];
	return 0;
}