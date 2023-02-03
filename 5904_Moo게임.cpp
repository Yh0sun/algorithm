#include <iostream>
using namespace std;

long arr[27] = { 0, };
long func(int k) {
	if (k == 0)return arr[0]=3;
	return arr[k] = func(k - 1) * 2 + k + 3;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	func(27);	//~1073741792
	
	int n, idx;
	cin >> n;

	while (n > 3) {

		for (idx = 0; idx < 27; idx++) {
			if (arr[idx] > n)break;
		}

		if (arr[idx - 1] + 1 == n) {
			cout << "m";
			return 0;
		}
		if (arr[idx - 1] + idx + 3 >= n) {
			cout << "o";
			return 0;
		}

		n -= arr[idx - 1] + idx + 3;
	}

	if (n == 1)cout << "m";
	else cout << "o";

	return 0;
}