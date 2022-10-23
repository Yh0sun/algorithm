#include <iostream>
#include <vector>
#include <queue>

#define Max 5000001

using namespace std;

int main() {

	int cityNum, busNum;
	cin >> cityNum >> busNum;

	if (cityNum == 1)return 0;

	vector<int> distance(cityNum + 1, Max);
	vector<int> visitedLineNum(cityNum + 1);
	vector<vector<pair<int,int>>> busLine(cityNum + 1,vector<pair<int, int>>());

	for (int i = 0; i < busNum; i++) {
		int _start, _end, _time;
		cin >> _start >> _end >> _time;
		busLine[_start].push_back(make_pair(_time, _end));
	}

	priority_queue<pair<int, int>> pq;
	distance[1] = 0;
	pq.push(make_pair(0, 1));

	while (!pq.empty()) {
		int currCity = pq.top().second;
		int currTime = -pq.top().first;
		pq.pop();

		if (distance[currCity] < currTime)continue;
		if (visitedLineNum[currCity] > cityNum - 1) {
			cout << "-1\n";
			return 0;
		}

		for (int i = 0; i < busLine[currCity].size(); i++) {
			int nextCity = busLine[currCity][i].second;
			int nextTime = currTime + busLine[currCity][i].first;

			if (distance[nextCity] > nextTime) {
				pq.push(make_pair(-nextTime, nextCity));
				distance[nextCity] = nextTime;
				visitedLineNum[nextCity] = visitedLineNum[currCity] + 1;
			}
			else if (distance[nextCity] == nextTime) {
				if (visitedLineNum[nextCity] > visitedLineNum[currCity] + 1) {
					pq.push(make_pair(-nextTime, nextCity));
					distance[nextCity] = nextTime;
					visitedLineNum[nextCity] = visitedLineNum[currCity] + 1;
				}
			}
		}
	}

	for (int i = 2; i <= cityNum; i++) {
		if (distance[i] == Max)cout << "-1\n";
		else cout << distance[i] << "\n";
	}

	return 0;
}
