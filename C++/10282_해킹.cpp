#include <iostream>
#include <vector>
#include <queue>

#define INF 100000000

using namespace std;

int main() {
	int testcase;
	int a, b, s;
	scanf("%d", &testcase);

	while (testcase--) {

		int comNum, dpdSize, start;
		int infectCom = 0, infectTime = 0;
		scanf("%d %d %d", &comNum, &dpdSize, &start);
		
		vector<int> minDistance(comNum + 1, INF);
		vector<vector<pair<int, int>>> dpd(comNum + 1);
		priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

		for (int i = 0; i < dpdSize; i++) {
			scanf("%d %d %d", &a, &b, &s);
			dpd[b].push_back({ s,a });
		}
	
		pq.push({ 0,start });
		minDistance[start] = 0;

		while (!pq.empty()) {
			int com = pq.top().second;
			int time = pq.top().first;
			pq.pop();

			if (minDistance[com] < time)continue;
			else {
				infectCom++;
				infectTime = time;
			}
			for (int i = 0; i < dpd[com].size(); i++) {

				int _com = dpd[com][i].second;
				int _time = dpd[com][i].first;

				if (minDistance[_com] > time + _time) {
					minDistance[_com] = time + _time;
					pq.push({ minDistance[_com] ,_com });
				}
			}
		}
		printf("%d %d\n", infectCom, infectTime);
	}
	return 0;
}
