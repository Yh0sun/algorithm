#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> cogs;
void leftMesh(int s, int d);
void rightMesh(int s, int d);

int main() {
	int cogNum, rotate, result = 0;
	int start, dir;

	cin >> cogNum;
	for (int i = 0; i < cogNum; i++) {
		string str;
		cin >> str;
		cogs.push_back(str);
	}

	cin >> rotate;
	for (int i = 0; i < rotate; i++) {
		cin >> start >> dir;

		if (start > 1) {
			if (cogs[start - 2][2] != cogs[start - 1][6]) leftMesh(start - 2, dir * (-1));
		}
		if (start < cogs.size()) {
			if (cogs[start][6] != cogs[start - 1][2]) rightMesh(start, dir * (-1));
		}

		if (dir < 0) {
			cogs[start - 1].push_back(cogs[start - 1][0]);
			cogs[start - 1] = cogs[start - 1].substr(1);
		}
		if (dir > 0) {
			cogs[start - 1] = cogs[start - 1][7] + cogs[start - 1];
			cogs[start - 1] = cogs[start - 1].substr(0, 8);
		}
	}

	for (int i = 0; i < cogs.size(); i++) {
		if (cogs[i][0] == '1')result++;
	}

	cout << result;
	return 0;
}

void leftMesh(int s, int d) {
	if (s > 0) {
		if (cogs[s-1][2] != cogs[s][6]) leftMesh(s - 1, d * (-1));
	}

	if (d < 0) {
		cogs[s].push_back(cogs[s][0]);
		cogs[s] = cogs[s].substr(1);
	}
	if (d > 0) {
		cogs[s] = cogs[s][7] + cogs[s];
		cogs[s] = cogs[s].substr(0, 8);
	}
}
void rightMesh(int s, int d) {
	if (s < cogs.size() - 1) {
		if (cogs[s + 1][6] != cogs[s][2]) rightMesh(s + 1, d * (-1));
	}

	if (d < 0) {
		cogs[s].push_back(cogs[s][0]);
		cogs[s] = cogs[s].substr(1);
	}
	if (d > 0) {
		cogs[s] = cogs[s][7] + cogs[s];
		cogs[s] = cogs[s].substr(0, 8);
	}
}