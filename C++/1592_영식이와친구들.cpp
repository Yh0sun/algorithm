#include <iostream>
#include<math.h>
using namespace std;
int tonum(char a);

int main() {
	string num;
	char a;
	int ten = 0, sum = 0, endnum;

	cin >> num;
	endnum = num.length();

	if (endnum > 6)
		cout << "최대 6자리수만 입력할 수 있습니다." << endl;
	else
		for (int i = 0; i < endnum; i++) {
			a = num.back();
			num.pop_back();
			sum = pow(16, i) * tonum(a);
			ten += sum;
		}

	cout << ten;

	return 0;
}

int tonum(char a) {
	if (a == '0') return 0;
	if (a == '1') return 1;
	if (a == '2') return 2;
	if (a == '3') return 3;
	if (a == '4') return 4;
	if (a == '5') return 5;
	if (a == '6') return 6;
	if (a == '7') return 7;
	if (a == '8') return 8;
	if (a == '9') return 9;
	if (a == 'A') return 10;
	if (a == 'B') return 11;
	if (a == 'C') return 12;
	if (a == 'D') return 13;
	if (a == 'E') return 14;
	if (a == 'F') return 15;
}
