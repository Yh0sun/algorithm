#include <iostream>
using namespace std;

int main() {
	int sausage, peo;
	int a, b, reminder = 100;

	cin >> sausage >> peo;

	if (sausage > peo) {
		a = sausage;
		b = peo;
	}
	else {
		a = peo;
		b = sausage;
	}

	while (reminder != 0) {
		reminder = a % b;
		a = b;
		b = reminder;
	}

	cout << peo - a;
	return 0;
}
