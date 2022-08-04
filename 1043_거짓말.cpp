#include<iostream>
#include<vector>
using namespace std;

int find(int a, vector<int>& parent) {
	if (parent[a] == a) 
		return a;

	parent[a] = find(parent[a], parent);
	return parent[a];
}
void join(int a, int b, vector<int>& parent) {
	a = find(a, parent);
	b = find(b, parent);

	if (a > b) parent[a] = b;
	else  parent[b] = a;
}
int main() {
	int n, m, trueNum;
	cin >> n >> m >> trueNum;

	int lie = m;
	vector<int> truePeople(trueNum);
	vector<vector<int>> attend;
	vector<int> parent(n + 1);

	for (int i = 1; i <= n; i++)
		parent[i] = i;
	
	for (int i = 0; i < trueNum; i++)
		cin >> truePeople[i];
	
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		
		vector<int> vec(num);
		for (int j = 0; j < num; j++) {
			cin >> vec[j];
			if (j > 0)join(vec[j], vec[j - 1], parent);
		}
		
		attend.push_back(vec);
	//	cout << attend.size();
		/*for (int j = 0; j < attend.size(); j++) {
			for (int k = 0; k < attend[j].size(); k++) {
				cout << attend[j][k];
			}
			cout << endl;
		}
		*/
	}

	for (int i = 0; i < trueNum; i++) {
		for (int j = 0; j < attend.size(); j++) {
			if (find(truePeople[i], parent) == find(attend[j][0], parent))lie -= 1;
		}
	}

	cout << lie << endl;
	return 0;
}
