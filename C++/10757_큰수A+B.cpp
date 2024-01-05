#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

int main() {
	string numA, numB, value, result;
	string n1, n2;
	int num1, num2, up = 0, val;

	cin >> numA >> numB;

	while (1) {
		if (!numA.empty()) {
			n1 = numA.back(); numA.pop_back();
		}
		else n1 = '0';
		if (!numB.empty()) {
			n2 = numB.back(); numB.pop_back();
		}
		else n2 = '0';

		num1 = stoi(n1);
		num2 = stoi(n2);


		val = (num1 + num2 + up) % 10;
		up = (num1 + num2 + up) / 10;

		value.push_back((char)(val + 48));

		if (numA.empty() && numB.empty()) {
			if (up == 1) value.push_back('1');
			break;
		}
	}

	char tmp;
	int size = value.size();

	for (int i = 0; i < size; i++) {
		tmp = value.back();
		result.push_back(tmp);
		value.pop_back();
	}
	cout << result;
	return 0;
}