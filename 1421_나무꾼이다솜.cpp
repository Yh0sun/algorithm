#include <iostream>

using namespace std;

int main() {
	int n, c, w;
	int val[51], max_val = 0;
	int k = 0, c_cnt = 0;
	long long sum, max_sum = 0;

	cin >> n >> c >> w;

	for (int i = 0; i < n; i++) {
		cin >> val[i];
		if (max_val < val[i])max_val = val[i];
	}

	for (int i = 1; i <= max_val; i++) {
		k = 0;
		c_cnt = 0;
		for (int j = 0; j < n; j++) {
			if (val[j] >= i) {
				int v = val[j] / i;
				int cc = (val[j] / i - 1);
				if (val[j] % i != 0)cc++;

				if (v * w * i > c * cc) {
					k += v;
					c_cnt += cc;
				}
			}
		}
		sum = (long long)k * i * w - (long long)c_cnt * c;
		if (max_sum < sum)max_sum = sum;

	}

	cout << max_sum;

	return 0;
}