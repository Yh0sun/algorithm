#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int x, y;
		cin >> x >> y;

		int dis = y - x;
		if (dis < 4) {
			cout << dis << "\n";
			continue;
		}

		int num = sqrt(dis);
		int ans = num * 2;
		if (num * num == dis)cout << ans - 1;
		else if (num * (num + 1) < dis)cout << ans + 1;
		else cout << ans;
		
		cout << "\n";
	}
	return 0;
}