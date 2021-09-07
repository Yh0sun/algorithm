#include<iostream>
using namespace std;

int main() {
	int sheet, goal, cardnum[100], sum = 0;
	int gap = 0, lowgap;

	cin >> sheet >> goal;

	lowgap = goal;

	for (int i = 0; i < sheet; i++)
		cin >> cardnum[i];

	for (int i = 0; i < sheet; i++)
		for (int j = i + 1; j < sheet; j++)
			for (int k = j + 1; k < sheet; k++) {
				sum = cardnum[i] + cardnum[j] + cardnum[k];
				gap = goal - sum;
				if (gap < lowgap && gap >= 0)lowgap = gap;
			}

	cout << goal - lowgap;
	return 0;
}