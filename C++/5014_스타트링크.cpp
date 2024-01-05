#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
  int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;

	vector<int> press_num(f + 1);
	queue<int> que;

	que.push(s);
	press_num[s] = 1;

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		if (cur + u <= f && press_num[cur + u] == 0) {
			que.push(cur + u);
			press_num[cur + u] = press_num[cur] + 1;
		}
		if (cur - d > 0 && press_num[cur - d] == 0) {
			que.push(cur - d);
			press_num[cur - d] = press_num[cur] + 1;
		}
	}

	if (press_num[g] != 0)cout << press_num[g] - 1;
	else cout << "use the stairs";

	return 0;
}
