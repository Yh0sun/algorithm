#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[20001] = { 0, };

//방향그래프가 주어지면 주어진 시작점에서 다른 모든 정점으로의 최단 경로를 구하는 프로그램을
// 정점 여러개를 거쳐가는 방법도 있음
//우선순위 큐


int main() {
	int numDot, numLine;
	int start;
	vector<int> visited;
	vector<priority_queue<pair<int, int>>> table(20001, priority_queue<pair<int, int>>());

	cin >> numDot >> numLine >> start;

	for (int i = 0; i < numLine; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		table[a].push({ b,c });
	}	

	for (int i = 0; i < table[start].size(); i++) {
		pair<int,int> p = table[start][i];
		if (arr[p.first] == 0 || arr[p.first] > p.second)arr[p.first] = p.second;
	}

	for (int i = 1; i <= table.size(); i++) {
		if (i == start)continue;
		else if (arr[i] == 0)continue;
		else {
			for (int j = 0; j < table[i].size(); j++) {
				pair<int, int> p = table[i][j];
				if (arr[p.first] == 0 || arr[p.first] > arr[i] + p.second)arr[p.first] = arr[i] + p.second;
			}
		}
	}

	for (int i = 1; i <= numDot; i++) {
		if (i == start)cout << "0" << endl;
		else if (arr[i] == 0)cout << "INF" << endl;
		else cout << arr[i] << endl;
	}

	return 0;
}
