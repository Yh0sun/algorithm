#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> numbers;

int binary_search(int start, int end, int num, int except1, int except2) {
	int mid;

	while (start <= end) {
		mid = (start + end) / 2;
		
		while (mid == except1 || mid == except2) {
			mid -= 1;
			if (mid < 0 || mid < start)return 0;
		}
		if (numbers[mid] == num)return 1;
		else if (numbers[mid] < num)start = mid + 1;
		else end = mid - 1;
	}

	return 0;
}

int main() {
	int n, num;
	int ans = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		numbers.push_back(num);
	}

	sort(numbers.begin(), numbers.end());
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)continue;
			if (binary_search(0, n - 1, numbers[i] - numbers[j], i, j)) {
				ans++;
				break;
			}
		}
	}

	cout << ans;
	return 0;
}
