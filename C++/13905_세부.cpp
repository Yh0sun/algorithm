#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[100001], num;
struct Line
{
	int start, end;
	int value;
};

bool comp(Line a, Line b) {
	return a.value > b.value;
}
int find(int i) {
	if (i == parent[i]) {
		return i;
	}
	else {
		int j = find(parent[i]);
		parent[i] = j;
		return j;
	}
}
void Union(Line a) {
	int x = find(a.start);
	int y = find(a.end);
	if (x != y)
		parent[y] = x;
}

int main() {
	int lineNum;
	int start, end;

	cin >> num >> lineNum >> start >> end;

	for (int i = 0; i < num; i++) {
		parent[i] = i;
	}

	vector<Line> line;

	Line tmp;
	for (int i = 0; i < lineNum; i++) {
		cin >> tmp.start >> tmp.end >> tmp.value;
		line.push_back(tmp);
	}

	sort(line.begin(), line.end(), comp);

	bool Reach = false;
	for (int i = 0; i < lineNum; i++) {
		Union(line[i]);
		if (find(start) == find(end)) {
			cout << line[i].value;
			Reach = true;
			break;
		}
	}
	//도달하지 못했을때
	if (!Reach)cout << 0;
	return 0;
}