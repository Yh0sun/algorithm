#include<iostream>
#include <vector>
using namespace std;

vector<int> x;

bool check(int h,int n) {
	int dot = 0;
	for (int i = 0; i < x.size(); i++) {
		if (x[i] - h > dot)return false;
		dot = x[i] + h;
	}
	if (dot < n)return false;
	return true;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, tmp;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> tmp;
		x.push_back(tmp);
	}

	int mid = 0;
	int begin = 0, end = n;
	while (begin <= end) {
		mid = (begin + end) / 2;

		if (check(mid, n))end = mid - 1;
		else begin = mid + 1;
	}

	cout << begin;
	return 0;
}