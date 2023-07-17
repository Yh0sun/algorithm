#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Bridge {
	int val;
	int s;
	int e;
};
bool comp(Bridge a, Bridge b) {
	return a.val > b.val;
}

int find(int a,vector<int>& p) {
	if (a == p[a])return a;
	return p[a] = find(p[a], p);
}
int merge(int a, int b, vector<int>& p) {
	a = find(a, p);
	b = find(b, p);
	return p[b] = a;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	vector<Bridge> bridges;
	vector<int> parents;
	int N, M, start, end, ans = 0;
	cin >> N >> M;

	for (int n = 0; n <= N; n++) {
		parents.push_back(n);
	}
	for (int m = 0; m < M; m++) {
		int a, b, c;
		cin >> a >> b >> c;
		bridges.push_back({ c,a,b });
	}
	cin >> start >> end;

	sort(bridges.begin(), bridges.end(),comp);

	for (int i = 0; i < bridges.size() ; i++) {
		merge(bridges[i].s, bridges[i].e, parents);
		ans = bridges[i].val;
		if (find(start, parents) == find(end, parents))break;
	}
	cout << ans;
	return 0;
}
