#include <iostream>
using namespace std;

int main() {
	int num = 0;
	char sco = 'A';

	cin >> num;

	if (num >= 90)
		sco = 'A';
	else if (num >= 80)
		sco = 'B';
	else if (num >= 70)
		sco = 'C';
	else if (num >= 60)
		sco = 'D';
	else
		sco = 'F';

	cout << sco;

	return 0;
}