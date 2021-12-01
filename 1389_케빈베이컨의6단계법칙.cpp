#include<iostream>
#include<queue>
using namespace std;
int visited[101];
int m;
int line1[101], line2[101];
queue<int> que;

void vacon(int a);
void reset() {
	for (int k = 0; k < 101; k++)
		visited[k] = 0;
}

int main() {
	int usernum;
	int sum[101] = { 0, };

	cin >> usernum >> m;

	for (int i = 0; i < m; i++)
		cin >> line1[i] >> line2[i];

	for (int i = 1; i <= usernum; i++) {
		for (int j = 1; j <= usernum; j++) {
			if (i != j) {
				que.push(i);
				visited[i] = 1;
				vacon(j);
				sum[i] += (visited[j] - 1);
			}
			reset();
			while (!que.empty())que.pop();
		}
	}

	int smallNum = 10000;
	int smallperson;
	for (int i = 1; i <= usernum; i++) {
		if (smallNum > sum[i]) {
			smallNum = sum[i];
			smallperson = i;
		}
	}
	cout << smallperson;
	return 0;
}

void vacon(int j) {
	while (true) {
		for (int a = 0; a < m; a++) {
			if (que.front() == line1[a] && visited[line2[a]] == 0) {
				que.push(line2[a]);
				visited[line2[a]] = visited[line1[a]] + 1;
				if (line2[a] == j) {
					que.push(0);
					break;
				}
			}
			if (que.front() == line2[a] && visited[line1[a]] == 0) {
				que.push(line1[a]);
				visited[line1[a]] = visited[line2[a]] + 1;
				if (line1[a] == j) {
					que.push(0);
					break;
				}
			}
		}
		if (que.back() == 0)break;
		que.pop();
	}
}