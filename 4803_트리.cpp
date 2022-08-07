#include <iostream>
#include <set>
using namespace std;

int parent[501];

int find(int a) {
	if (parent[a] == a)
		return a;
	return parent[a] = find(parent[a]);
}
void join(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) {
		parent[a] = 0;
		parent[b] = 0;
	}
	else if (a > b) parent[a] = b;
	else parent[b] = a;
}

int main() {

	for (int i = 1;; i++) {

		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0)break;

		for (int j = 1; j <= n; j++) {
			parent[j] = j;
		}

		for (int j = 0; j < m; j++) {
			int node1, node2;
			cin >> node1 >> node2;
			join(node1, node2);
		}

		set<int> result;
		for (int j = 1; j <= n; j++) {
			int prt = find(j);
			if (prt != 0)result.insert(prt);
		}	

		if (result.size() == 0) printf("Case %d: No trees.\n", i);
		else if (result.size() == 1)printf("Case %d: There is one tree.\n", i);
		else printf("Case %d: A forest of %d trees.\n", i, result.size());
	}
	return 0;
}
