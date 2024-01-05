#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

	int room_num, d;
	char kind[1001];
	int fee[1001];

	while (true) {
		vector<vector<int>> door;
		string ans = "No";
		cin >> room_num;
		if (room_num == 0)break;

		for (int i = 0; i < room_num; i++) {
			cin >> kind[i] >> fee[i];

			vector<int> tmp;
			while (true) {
				cin >> d;
				if (d == 0)break;
				tmp.push_back(d);
			}
			door.push_back(tmp);
		}
	
		queue<int> que;
		vector<int> visited(room_num, -1);
		que.push(0);
		visited[0] = 0;
		
		while (!que.empty()) {
			int cur = que.front();
			int cur_fee = visited[cur];
			que.pop();

			if (cur == room_num - 1) {
				ans = "Yes";
				break;
			}

			for (int j = 0; j < door[cur].size(); j++) {
				int next_room = door[cur][j] - 1;
			
				if (visited[next_room] >= cur_fee) continue;
				
				if (kind[next_room] != 'T') {
					que.push(next_room);
					if (fee[next_room] > cur_fee)visited[next_room] = fee[next_room];
					else visited[next_room] = cur_fee;
				}
				else if (fee[next_room] <= cur_fee) {
					que.push(next_room);
					visited[next_room] = cur_fee - fee[next_room];					
				}
			}
		}

		cout << ans << "\n";
	}

	return 0;
}
