#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[20001] = { 0, };

int main() {
	int numDot, numLine;
	int start;
	vector<vector<pair<int, int>>> table(20001, vector<pair<int, int>>());
	vector<int> visited;
	
	cin >> numDot >> numLine >> start;

	for (int i = 0; i < numLine; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		table[a].push_back({ b,c });
	}

	visited.push_back(start);

	for (int i = 0; i < table[start].size(); i++) {
		pair<int, int> p = table[start][i];
		if (arr[p.first] == 0 || arr[p.first] > p.second)arr[p.first] = p.second;
	}

	while (true) {

		int m = 100;
		int mDot = -1;
		for (int i = 1; i <= numDot; i++) {
			if (arr[i] < m && find(visited.begin(),visited.end(),i)==visited.end()) {
				m = arr[i];
				mDot = i;
			}
		}
		if (mDot == -1) break;
		visited.push_back(mDot);

		for (int j = 0; j < table[mDot].size(); j++) {
			pair<int, int> p = table[mDot][j];
			if (arr[p.first] == 0 || arr[p.first] > arr[mDot] + p.second)arr[p.first] = arr[mDot] + p.second;
		}

		if (visited.size() == numDot)break;

	}

	for (int i = 1; i <= numDot; i++) {
		if (i == start)cout << "0" << endl;
		else if (arr[i] == 0)cout << "INF" << endl;
		else cout << arr[i] << endl;
	}

	return 0;
}
