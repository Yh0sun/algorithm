#include <iostream>
using namespace std;

int reflection(int h, int w, int i, int j) {
	
	if (h == 2) {
		if (i == 1 && j == 2)return 0;
		return 1;
	}

	int next_j;
	if (i <= h / 2) next_j = j - w / 4 - 1;  
	else next_j = j % (w / 2 + 1);
	
	if (i > h / 2 && j >= w / 2 - (h - i) && j <= w / 2 + (h - i))return 0;
	else return reflection(h / 2, w / 2-1, i % (h / 2+1), next_j);
}

int main() {
	int n, cnt = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 2 - 1; j++) {
			if (j >= (n - 1) - i && j <= (n - 1) + i) {
				if (reflection(n - 1, (n - 1) * 2, i, j))printf("*");
				else printf(" ");
			}
			else printf(" ");
		}
		printf("\n");
	}

	return 0;
}
