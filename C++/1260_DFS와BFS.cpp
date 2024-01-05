#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int DfsVisited[1001] = { 0, }, BfsVisited[1001] = { 0, };
int pointNum, lineNum;
int p_start[10001], p_end[10001];
queue<int> bfs;
void dfsSearch(int v);
void bfsSearch(int v);

int main() {
	int start;
	
	cin >> pointNum >> lineNum >> start;
	
	for (int i = 0; i < lineNum; i++) {
		cin >> p_start[i] >> p_end[i];
	}

	dfsSearch(start); 
	cout << endl;
	
	BfsVisited[start] = 1;
	bfs.push(start);
	
	while (!bfs.empty()) {
		cout << bfs.front() << " ";
		bfsSearch(bfs.front());
		bfs.pop();
	}
	
	return 0;
}

void dfsSearch(int v) {
	int next[1001] = { 0, };
	int count = 0;

	DfsVisited[v] = 1;
	cout << v << " ";

	for (int i = 0; i < lineNum; i++) {
		if (p_start[i] == v && DfsVisited[p_end[i]] == 0) {
			next[count] = p_end[i];
			count++;
		}
		if (p_end[i] == v && DfsVisited[p_start[i]] == 0) {
			next[count] = p_start[i];
			count++;
		}
	}
	sort(next, next + count);
	for (int i = 0; i < count; i++)
		if (next[i] != 0 && DfsVisited[next[i]] == 0)
			dfsSearch(next[i]);
}

void bfsSearch(int v) {
	int next[1001] = { 0, };
	int count = 0;

	for (int i = 0; i < lineNum; i++) {
		if (p_start[i] == v && BfsVisited[p_end[i]] == 0) {
			next[count] = p_end[i];
			count++;
			BfsVisited[p_end[i]] = 1;
		}
		if (p_end[i] == v && BfsVisited[p_start[i]] == 0) {
			next[count] = p_start[i];
			count++;
			BfsVisited[p_start[i]] = 1;
		}
	}
	sort(next, next + count);
	for (int i = 0; i < count; i++)
		if (next[i] != 0)
			bfs.push(next[i]);
}