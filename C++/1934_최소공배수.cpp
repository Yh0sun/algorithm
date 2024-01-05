#include<iostream>
using namespace std;

int main() {
	int testcase;
	int num1, num2;
	int multipleNum1, multipleNum2;

	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		cin >> num1 >> num2;
		multipleNum1 = num1;
		multipleNum2 = num2;
		while (true) {
			if (multipleNum1 > multipleNum2)multipleNum2 += num2;
			else if (multipleNum1 < multipleNum2)multipleNum1 += num1;
			else {
				cout << multipleNum1 << endl;
				break;
			}
		}
	}

	return 0;
}