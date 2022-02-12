#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int check[10001] = { 0, };
int dot;

struct Line {
	int start, end;
	int value;
};

bool comp(Line a, Line b) {
	return a.value < b.value;
}

bool isVisited(Line a) {
	if (check[a.start] != check[a.end])
		return false;
	else return true;
}

void toMST(Line a) {
	int t = check[a.end];
	check[a.end] = check[a.start];
	for (int i = 1; i <= dot; i++) {
		if (check[i] == t) check[i] = check[a.start];
	}
}

int main() {

	int lineNum;
	long long result = 0;
	int cnt = 0;

	vector<Line> line;
	Line tmp;
	
	cin >> dot >> lineNum;
	
	for (int i = 1; i <= dot; i++) {
		check[i] = i;
	}

	int temp1, temp2, temp3;
	for (int i = 0; i < lineNum; i++) {
		cin >> temp1 >> temp2 >> temp3;
		tmp.start = temp1;
		tmp.end = temp2;
		tmp.value = temp3;

		line.push_back(tmp);
	}

	sort(line.begin(), line.end(), comp);

	for (int i = 0; i < lineNum; i++) {
		if (!isVisited(line[i])) {
			result += line[i].value;
			toMST(line[i]);
			cnt++;
		}
		if (cnt == dot - 1)break;
	}

	cout << result;
	return 0;
}