#include <iostream>

using namespace std;

int main() {
	int day, ddung;
	int multiA, multiB;
	int a, b;

	cin >> day >> ddung;

	for (int i = 0; i < day; i++) {
		if (i == 0) {
			multiA = 1;
			multiB = 0;
		}
		else if (i == 1) {
			multiA = 0;
			multiB = 1;
		}
		else {
			int tmp = multiA;
			multiA = multiB;
			multiB = tmp + multiB;
		}
	}
	for (int j = 1; ; j++) {
		if ((ddung - multiA * j) % multiB == 0) {
			a = j;
			b = (ddung - multiA * j) / multiB;
			break;
		}
	}
	cout << a << endl << b;
	return 0;
}