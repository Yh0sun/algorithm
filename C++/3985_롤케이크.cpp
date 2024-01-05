#include<iostream>
using namespace std;

int main() {
	int numofperson, lengthoflol;
	int countnum, real_high = 0, real_highperson = 0;
	int p, k, guess_high = 0, guess_highperson = 0;
	int arr[1000] = { 0 };

	cin >> lengthoflol >> numofperson;

	for (int i = 1; i <= numofperson; i++) {
		cin >> p >> k;
		if (guess_high < (k - p + 1)) {
			guess_high = k - p + 1;
			guess_highperson = i;
		}
		for (int j = p; j <= k; j++) {
			if (arr[j] == 0)arr[j] = i;
			else continue;
		}
	}

	for (int i = 1; i <= numofperson; i++) {
		countnum = 0;
		for (int j = 1; j <= lengthoflol; j++) {
			if (arr[j] == i) countnum++;
		}
		if (real_high < countnum) {
			real_high = countnum;
			real_highperson = i;
		}
		else continue;
	}

	cout << guess_highperson << endl << real_highperson;
	return 0;
}