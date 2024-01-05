#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, c;
vector<int> house;

int binary_search(int start, int end) {
	int ans;
	int mid;

	while (start <= end) {
		int cnt = 1;
		int spot = house[0];
		mid = (start + end) / 2;

		for (int i = 1; i < n; i++) {
			if (house[i] - spot >= mid) {
				cnt++;
				spot = house[i];
			}
		}

		if (cnt >= c) {
			ans = mid;
			start = mid + 1;
		}
		else 
			end = mid - 1;
	}
	return ans;
}
int main() {
	int h;
	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		cin >> h;
		house.push_back(h);
	}

	sort(house.begin(), house.end());
	cout << binary_search(1, house[n - 1] - house[0]);

	return 0;
}