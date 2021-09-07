#include <iostream>
using namespace std;

int main() {

	int score[5] = { 0 }, aver = 0;
	for (int i = 0; i < 5; i++) {
		cin >> score[i];
		if (score[i] < 40) score[i] = 40;
		aver += score[i];
	}
	aver = aver / 5;
	cout << aver;

	return 0;
}