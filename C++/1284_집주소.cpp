#include <iostream>
#include<stdlib.h>
#include<string>
using namespace std;
int countspace(int in);

int main() {

	string width[100];
	int input[100];

	for (int i = 0; ; i++) {
		cin >> input[i];
		if (input[i] == 0) break;
		if (input[i] >= 0 && input[i] <= 9999) {
			width[i] = to_string(countspace(input[i]));
		}
		else
			cout << "입력 범위를 초과하였습니다." << endl;
	}

	for (int j = 0; j < 100; j++) {
		cout << width[j] << endl;
		if (width[j].empty()) break;
	}

	return 0;
}
int countspace(int in) {

	int sum = 1;
	string num = to_string(in);

	while (1) {
		if (num.back() == '0') sum += 4;
		else if (num.back() == '1') sum += 2;
		else sum += 3;
		num.pop_back();
		sum++;
		if (num.empty()) break;
	}

	return sum;
}