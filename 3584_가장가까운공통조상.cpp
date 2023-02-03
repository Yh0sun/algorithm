#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n, a, b, node1, node2;
		cin >> n;

		vector<int> table(n + 1);
		vector<int> visited(n + 1);
		for (int i = 1; i < n; i++) {
			cin >> a >> b;
			table[b] = a;
		}

		cin >> node1 >> node2;
		int par1 = node1, par2 = node2;

		while (true) {
			if(par1>0)visited[par1]++;
			if(par2>0)visited[par2]++;
			
			if (par1>0&&visited[par1] == 2) {
				cout << par1 << "\n";
				break;
			}
			if (par2>0&&visited[par2] == 2) {
				cout << par2 << "\n";
				break;
			}

			par1 = table[par1];
			par2 = table[par2];
		}	
	}
	return 0;
}