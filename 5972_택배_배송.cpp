#include <iostream>
#include <vector>
#include <queue>
#define maximum 50000000
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int barnNum, cowNum;
	int barn1, barn2, cow;
	cin >> barnNum >> cowNum;

	vector<vector<pair<int, int>>> table(barnNum + 1, vector<pair<int, int>>());
	vector<int> dis(barnNum + 1, maximum);
	for (int i = 0; i < cowNum; i++) {
		cin >> barn1 >> barn2 >> cow;
		table[barn1].push_back({ barn2,cow });
		table[barn2].push_back({ barn1,cow });
	}

	priority_queue<pair<int, int>> pq;
	pq.push({ 0,1 });
	dis[1] = 0;

	while (!pq.empty()) {
		int cur_dis = -pq.top().first;
		int cur_barn = pq.top().second;
		pq.pop();

		if (dis[cur_barn] < cur_dis)continue;

		for (int i = 0; i < table[cur_barn].size(); i++) {
			int next_dis = table[cur_barn][i].second + dis[cur_barn];
			int next_barn = table[cur_barn][i].first;

			if (next_dis < dis[next_barn]) {
				dis[next_barn] = next_dis;
				pq.push({ -dis[next_barn],next_barn });
			}
		}
	}
	cout << dis[barnNum];
	return 0;
}