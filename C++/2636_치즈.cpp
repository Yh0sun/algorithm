#include <iostream>
#include <queue>
using namespace std;

int main() {
	int height, width;
	int cheese[100][100] = { 0, };
	int cnt1 = 0, cnt2 = 0;

	cin >> height >> width;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> cheese[i][j];
		}
	}

	int x[4] = { 0,0,1,-1 };
	int y[4] = { 1,-1,0,0 };

	for (int a = 0;; ++a) {

		queue<pair<int, int>> que;
		int history[100][100] = { 0, };

		que.push({ 0,0 });
		history[0][0] = 1;
		cheese[0][0] = 2;
		cnt1 = 1;

		while (!que.empty()) {

			pair<int, int> curr = que.front();
			que.pop();
			for (int i = 0; i < 4; i++) {
				int nx = curr.first + x[i];
				int ny = curr.second + y[i];
				if (nx >= 0 && nx < height && ny >= 0 && ny < width) {
					if (history[nx][ny] == 0 && (cheese[nx][ny] == 0 || cheese[nx][ny] == 2)) {
						que.push({ nx,ny });
						history[nx][ny] = 1;
						cheese[nx][ny] = 2;
						cnt1++;
					}
				}
			}
		}

		if (cnt1 == height * width) {
			cout << a << endl << cnt2;
			break;
		}

		cnt2 = 0;

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (cheese[i][j] == 1) {
					cnt2++;
					for (int k = 0; k < 4; k++) {
						int nx = i + x[k];
						int ny = j + y[k];
						if (nx >= 0 && nx < height && ny >= 0 && ny < width) {
							if (cheese[nx][ny] == 2) {
								cheese[i][j] = 0;
								break;
							}
						}
					}
				}
			}
		}

	}

	return 0;
}
