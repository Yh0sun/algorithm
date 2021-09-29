#include <iostream>
using namespace std;

int main() {
	int num, score[100] = { 0 }, standard[100] = { 0 };
	int count = 0;

	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> score[i];
	}

	standard[num - 1] = score[num - 1];
	for (int i = 1; i < num; i++) {
		standard[num - 1 - i] = score[num - 1] - i;
	}

	for (int i = num - 2; i >= 0; i--) {
		if (score[i] >= standard[i]) count += score[i] - standard[i];
		else {
			standard[i] = score[i];
			for (int j = i - 1; j >= 0; j--) {
				standard[j] = standard[i] - i + j;
			}
		}
	}
	cout << count;
	return 0;
}