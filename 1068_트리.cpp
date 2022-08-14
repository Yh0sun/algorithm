#include <iostream>
#include <vector>

using namespace std;

struct node
{
	int left = -1;
	int right = -1;
};
void rm(int x, vector<node>& nodes);

int main() {

	int n, leaf = 0;
	cin >> n;

	vector<node> nodes(n);
	for (int i = 0; i < n; i++) {
		int par;
		cin >> par;
		if (par != -1) {
			if (nodes[par].left == -1)nodes[par].left = i;
			else nodes[par].right = i;
		}
	}

	int rm_node;
	cin >> rm_node;
	rm(rm_node, nodes);

	for (int i = 0; i < nodes.size(); i++) {
		if (nodes[i].left == -1 && (nodes[i].right == -1 || nodes[i].right == rm_node))leaf++;
		else if (nodes[i].right == -1 && (nodes[i].left == -1 || nodes[i].left == rm_node))leaf++;
	}

	cout << leaf;
	return 0;
}
void rm(int x, vector<node>& nodes) {

	int left = nodes[x].left;
	int right = nodes[x].right;

	nodes[x].left = 100;
	nodes[x].right = 100;

	if (left != -1)rm(left, nodes);
	if (right != -1)rm(right, nodes);
}
