#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int binary_search(int start, int end, int target,vector<int>& obstacle) {

	int mid;
	while (start <= end) {
		mid = (start + end) / 2;
		if (obstacle[mid] > target) end = mid - 1;
		else start = mid + 1;
	}
	return start;
}
int main() {
	int n, h, obt;
	int min_val = 200000, cnt = 0;
	vector<int> upper_obstacle;
	vector<int> down_obstacle;

	cin >> n >> h;
	for (int i = 0; i < n; i++) {
		cin >> obt;
		if (i % 2 == 0) down_obstacle.push_back(obt);
		else upper_obstacle.push_back(obt);
	}

	sort(upper_obstacle.begin(), upper_obstacle.end());
	sort(down_obstacle.begin(), down_obstacle.end());

	for (int i = 1; i <= h; i++) {
		int upper_val = n / 2 - binary_search(0, n / 2 - 1, h - i - 1, upper_obstacle);
		int down_val = n / 2 - binary_search(0, n / 2 - 1, i, down_obstacle);

		if (min_val == upper_val + down_val)cnt++;
		if (min_val > upper_val + down_val) {
			min_val = upper_val + down_val;
			cnt = 1;
		}
	}
	printf("%d %d", min_val, cnt);
	return 0;
}