#include <iostream>
using namespace std;

int building[51] = { 0, };
int check[51][51] = { 0, };

int main() {
	int n, max_cnt = 0;
	cin >> n;

	for (int i = 0; i < n; i++) 
		cin >> building[i];

	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (i>=j) {
				if (check[j][i] == 1)cnt++;
				continue;
			}

			double slope = (1.0 * building[j] - building[i]) / (1.0 * j - i);
			bool flag = true;

			for (int k = 1; k < j - i; k++) {
				if (slope > 0) {
					if (building[i + k] > building[i]) {
						if (slope * k <= 1.0 * building[i + k] - building[i]) {
							flag = false;
							break;
						}
					}
				}
				else if (slope < 0) {
					if (building[i + k] >= 1.0 * building[i] + slope * k) {
						flag = false;
						break;
					}
				}
				else {
					if (building[i + k] >= building[i]) {
						flag = false;
						break;
					}
				}
			}
			if (flag) {
				check[i][j] = 1;
				cnt++;
			}
		}
		if (max_cnt < cnt)max_cnt = cnt;
	}
	cout << max_cnt;
	return 0;
}
