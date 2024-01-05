#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, m;
	int ladder_snack[101] = { 0, };
	cin >> n >> m;

	for (int i = 0; i < n + m; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		ladder_snack[tmp1] = tmp2;
	}

	queue<int> que;
	int visited[101] = { 0, };
	que.push(1);
	visited[1] = 1;

	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		
		if (cur == 100)break;

		for (int i = 1; i < 7; i++) {
			if (cur + i > 100)continue;
			if (visited[cur + i] != 0)continue;
			if (visited[ladder_snack[cur + i]] != 0)continue;
			if (ladder_snack[cur + i] == 0) {
				que.push(cur + i);
				visited[cur + i] = visited[cur] + 1;
			}
			else {
				que.push(ladder_snack[cur + i]);
				visited[cur + i] = visited[cur] + 1;
				visited[ladder_snack[cur + i]] = visited[cur] + 1;
			}
		}
	}
	cout << visited[100] - 1;
	
	return 0;
}
