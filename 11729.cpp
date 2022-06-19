#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<stack<int>> st;
int nextMove(int top);

int main() {
	int n;
	vector<vector<int>> history;
	history.push_back({ 0,0 });

	cin >> n;
	
	stack<int> s;
	for (int i = 0; i < 4; i++) {
		st.push_back(s);
	}
	for (int i = n; i > 0; i--) {
		st[1].push(i);
		cout << st[1].top();
	}

	for (int i = 1;; i++) {

		vector<int> v;

		if (!st[1].empty() && history[i - 1][1] != 1 && nextMove(st[1].top()) != 0) {
			st[nextMove(st[1].top())].push(st[1].top());
			st[1].pop();
			v.push_back(1);
			v.push_back(nextMove(st[1].top()));
			cout << nextMove(st[1].top()) << endl;
			cout << v[0] << " " << v[1] << endl;
		}
		else if (!st[2].empty() && history[i - 1][1] != 2 && !nextMove(st[2].top()) != 0) {
			st[nextMove(st[2].top())].push(st[2].top());
			st[2].pop();
			v.push_back(2);
			v.push_back(nextMove(st[2].top()));
			cout << nextMove(st[2].top()) << endl;
			cout << v[0] << " " << v[1] << endl;
		}
		else if (!st[3].empty() && history[i - 1][1] != 3 && !nextMove(st[3].top()) != 0) {
			st[nextMove(st[3].top())].push(st[3].top());
			st[3].pop();
			v.push_back(3);
			v.push_back(nextMove(st[3].top()));
			cout << nextMove(st[3].top()) << endl;
			cout << v[0] << " " << v[1] << endl;
		}
		else {
			cout << "false" << endl;
		}

		history.push_back(v);

		if (st[1].empty() && st[2].empty()) {
			cout << i << endl;
			break;
		}
	}

	for (int i = 1; i < history.size(); i++) {
		cout << history[i][0] << " " << history[i][1] << endl;
	}

	return 0;
}
int nextMove(int top) {
	cout << "next" << endl;
	if (st[3].empty()) return 3;
	else if (st[2].empty()) return 2;
	else if (st[1].empty()) return 1;
	else if (top < st[3].top()) return 3;
	else if (top < st[2].top()) return 2;
	else if (top < st[1].top()) return 1;
	else return 0;
}
