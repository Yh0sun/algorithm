#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0)return a;
	return gcd(b, a % b);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase, m, n, x, y;
	cin >> testcase;

	while (testcase--) { 
		cin >> m >> n >> x >> y;

		int g, num,ans = -1;
		int tmp1 = 0, tmp2 = 0, cnt1 = 0, cnt2 = 0;
		
		if (m > n)g = gcd(m, n);
		else g = gcd(n, m);
		num = m * n / g;

		while (tmp1 <= num && tmp2 <= num) {
			tmp1 = m * cnt1 + x;
			tmp2 = n * cnt2 + y;

			if (tmp1 == tmp2) {
				ans = tmp1;
				break;
			}

			if (tmp1 > tmp2)cnt2++;
			if (tmp1 < tmp2)cnt1++;
		}
		cout << ans << "\n";
	}

	return 0;
}