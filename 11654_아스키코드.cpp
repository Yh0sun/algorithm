#include <iostream>
using namespace std;

int main() {

	char in = 'A', next, point = '0';
	int aski = 48;

	cin >> in;

	for (int i = 0; i < 75; i++) {
		if (point == in) {
			aski += i;
			break;
		}
		else
			++point;
	}

	cout << aski;
	return 0;
}