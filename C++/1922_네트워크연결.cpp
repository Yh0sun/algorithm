#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class comp {

public:bool operator()(pair<int, int> a, pair<int, int>b) {
	return a.second > b.second;
}
};

priority_queue < pair<int, int>, vector<pair<int, int>>, comp> oneOf;
vector<int> visited;

bool isInVisited(pair<int,int> a) {
	for (int i = 0; i < visited.size(); i++) {
		if (visited[i] == a.first) {
			return true;
			break;
		}
	}
	return false;
}

void removeL() {
	
	while (true)
	{
		bool out = false;
		for (int i = 0; i < visited.size(); i++) {
			if (visited[i] == oneOf.top().first) {
				oneOf.pop();
				out = true;
				break;
			}
		}
		if (!out)break;
	}
}
int main() {

	int com, lineNum;
	
	cin >> com >> lineNum;

	vector<vector<pair<int,int>>> line;
	line.resize(100000);
	vector<vector<int>> value;
	
	int result = 0;
	int temp1, temp2, temp3;

	for (int i = 0; i < lineNum; i++) {
		cin >> temp1 >> temp2 >> temp3;
		line[temp1].push_back(make_pair(temp2, temp3));
		line[temp2].push_back(make_pair(temp1, temp3));
	}

	visited.push_back(temp1);

	for (int k = 0; k < com - 1; k++) {

		for (int j = 0; j < line[visited[k]].size(); j++) {
			if (!isInVisited(line[visited[k]][j])) {
				oneOf.push(line[visited[k]][j]);
			}
		}
		removeL();
		result += oneOf.top().second;
		visited.push_back(oneOf.top().first);
	//	cout << oneOf.top().first << " " << oneOf.top().second << endl;
		oneOf.pop();
	}
	cout << result;
	return 0;
}