#include <iostream>

using namespace std;
int parent[501] = { 0, };

void findFun(int a)
{
	if (parent[a] != a) {
		findFun(parent[a]);

	}
}
void unionFun(int a, int b)
{
	if (parent[b] != b) {
		findFun(parent[b]);
	}
}

int main() {
	
	while (true) {
		int n, m;
		cin >> n >> m;

		if (n == 0 && m == 0) break;

		for (int i = 1; i <= n; i++) {
			parent[i] = i;
		}

		for (int i = 0; i < m; i++) {
			int node1, node2;
			cin >> node1 >> node2;
		}
		//memset
	}
	return 0;
}
