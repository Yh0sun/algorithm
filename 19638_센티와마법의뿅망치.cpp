#include<iostream>
#include<queue>
using namespace std;

int main() {
	int peo, centi, t;
	int g;
	priority_queue<int> giant;

	cin >> peo >> centi >> t;
	for (int i = 0; i < peo; i++) {
		cin >> g;
		giant.push(g);
	}

	for (int i = 1; i <= t; i++) {
		if (i == 1 && giant.top() < centi) {
			cout << "YES" << endl << 0;
			break;
		}
		giant.push(giant.top() / 2);
		giant.pop();
		if (giant.top() == 0)giant.push(1);
		if (giant.top() < centi) {
			cout << "YES" << endl << i;
			break;
		}
		else if (i == t) cout << "NO" << endl << giant.top();
	}

	return 0;
}