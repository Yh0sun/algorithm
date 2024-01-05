#include <iostream>
#include <vector>
using namespace std;

int main() {

	int node, degree1;
	cin >> node >> degree1;

	vector<int> tree(node);
	int prt = 0;

	for (int i = 1; i < tree.size(); i++) {
		if (node - degree1 < i) {
			tree[i] = prt;
		}
		else {
			tree[i] = prt;
			prt++;
		}
		cout << tree[i] << " " << i << endl;
	}
	
	return 0;
}
