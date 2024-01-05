#include<iostream>
using namespace std;
char match[10][10];
bool square(int pointa_x, int pointa_y, int pointb_x, int pointb_y) {
	bool Isitsquare = true;
	
	for (int r = pointa_y; r <= pointb_y; r++) {
		if (match[pointa_x][r] == '.')Isitsquare = false;
	}
	for (int x = pointa_x; x <= pointb_x; x++) {
		if (match[x][pointa_y] == '.')Isitsquare = false;
	}
	for (int y = pointa_y; y <= pointb_y; y++) {
		if (match[pointb_x][y] == '.')Isitsquare = false;
	}
	for (int z = pointa_x; z <= pointb_x; z++) {
		if (match[z][pointb_y] == '.')Isitsquare = false;
	}
	return Isitsquare;
};

int main() {
	
	int dotCount = 0;
	int resultA = 0, resultB = 0;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> match[i][j];
			if (match[i][j] == '.') dotCount++;
		}
	}
	
	resultA = (dotCount - 36) / 2;
	
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			for (int z = 1; z <= 3; z++)
				if (x + z * 3 < 10 && x + z * 3 < 10) {
					if (square(x, y, x + z * 3, y + z * 3))resultB++;
				}
				else continue;
		}
	}
	cout << resultA << " " << resultB;
	return 0;
}