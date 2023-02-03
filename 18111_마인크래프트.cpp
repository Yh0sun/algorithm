#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	/*ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*/

	int N, M, B, tmp;
	int min_sec = 128000000, max_h = -1;
	cin >> N >> M >> B;

	vector<vector<int>> map;
	for (int i = 0; i < N; i++) {
		vector<int> vec;
		for (int j = 0; j < M; j++) {
			cin >> tmp;
			vec.push_back(tmp);
		}
		map.push_back(vec);
	}

	for (int k = 0; k < 257; k++) {
		int sec = 0;
		int tmp_B = B;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == k)continue;
				else if (map[i][j] < k) {
					sec += k - map[i][j];
					tmp_B -= k - map[i][j];
				}
				else {
					sec += (map[i][j] - k) * 2;
					tmp_B += map[i][j] - k;
				}
			}
		}
		if (tmp_B < 0)break;

		if (min_sec >= sec) {
			min_sec = sec;
			max_h = k;
		}
	}

	cout << min_sec << " " << max_h;
	return 0;
}
