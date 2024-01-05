#include<iostream>
using namespace std;
//int swap(int a, int b) {};

int main() {

	int side1 = 1, side2 = 1, side3 = 1, rmp = 0;
	int result[1000] = { 0 };

	while (true) {

		cin >> side1 >> side2 >> side3;

		if (side1 == 0 && side2 == 0 && side3 == 0) break;
		//if (side1 == 1)break;
		rmp++;

		if (side3 < side1) swap(side1, side3);
		else if (side3 < side2) swap(side2, side3);

		if (side3 * side3 == side1 * side1 + side2 * side2) result[rmp] = 1;
		else  result[rmp] = 0;

	}

	for (int i = 1; i <= rmp; i++) {
		if (result[i] == 1) cout << "right" << endl;
		else cout << "wrong" << endl;
	}

	return 0;
}

/*int swap(int a, int b) {
	int tmp;
	tmp = a;
	a = b;
	b = tmp;

	return a, b;
}*/