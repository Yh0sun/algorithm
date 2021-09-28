#include<iostream>
using namespace std;

int main() {
	int num, result = 0;
	cin >> num;
	
	while (num > 0) {

		if (num / 5 != 0 && (num % 3 != 0 || num % 5 == 0)) {
			num -= 5;
			result++;
		}
		else if (num / 3 != 0 && num % 3 == 0) {
			num -= 3;
			result++;
		}
		else {
			result = -1;
			break;
		}
	}

	cout << result;
	return 0;
}