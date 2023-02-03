#include <iostream>
#include <map>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case, peo_num, paper, interview;
	cin >> test_case;

	for (int i = 0; i < test_case; i++) {
		cin >> peo_num;
		
		int ans = 1;
		map<int, int> order;

		for (int j = 0; j < peo_num; j++) {
			cin >> paper >> interview;
			order[paper] = interview;
		}

		int max_val = order[1];
		for (int j = 2; j <= peo_num; j++) {
			if (order[j] < max_val) {
				ans++;
				max_val = order[j];
			}
		}
		cout << ans << "\n";
	}
	return 0;
}