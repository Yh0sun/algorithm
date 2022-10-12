#include <iostream>

using namespace std;

int reflection(int n, int i, int j) {
	if (i / (n / 3) == 1 && j / (n / 3) == 1)return 0;
	if (n == 3)return 1;
	return reflection(n / 3, i % (n / 3), j % (n / 3));
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (reflection(n, i, j))printf("*");
			else printf(" ");
		}
		printf("\n");
	}

	return 0;
}
