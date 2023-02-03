#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {

	int sum = 0;
	string input;
	cin >> input;

	sort(input.begin(), input.end(), greater<>());

	for (int i = 0; i < input.length(); i++) {
		sum += input[i] - '0';
	}
	
	if (sum % 3 == 0 && input.back() == '0') {
		cout << input;
		return 0;
	}

	cout << "-1";
	return 0;
}
