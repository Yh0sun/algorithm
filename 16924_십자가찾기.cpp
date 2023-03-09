#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
char map[100][100][2];

int counter(int x, int y) {
	int cnt = 0;

	while (++cnt) {
		if (x + cnt >= n || x - cnt < 0 || y + cnt >= m || y - cnt < 0)break;
		if (map[x + cnt][y][0] != '*' || map[x - cnt][y][0] != '*' || map[x][y - cnt][0] != '*' || map[x][y + cnt][0] != '*')break;
		
		map[x + cnt][y][1] = '*';
		map[x - cnt][y][1] = '*';
		map[x][y - cnt][1] = '*';
		map[x][y + cnt][1] = '*';
	}
	if (cnt - 1 != 0) {
		map[x][y][1] = '*';
	}
	return cnt - 1;
}
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	fill(&(map[0][0][0]), &(map[0][0][0]) + 20000, '.');
	vector<vector<int>>ans;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j][0];
		}
	}

	for (int i = 1; i < n-1; i++) {
		for (int j = 1; j < m-1; j++) {
			if (map[i][j][0] == '*') {
				int star_size = counter(i, j);
				if (star_size!=0)ans.push_back({ i + 1, j + 1, star_size });
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j][0] != map[i][j][1]) {
				cout << "-1";
				return 0;
			}
		}
	}

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i][0] <<" " << ans[i][1]<<" " << ans[i][2] << "\n";
	}
	return 0;
}
