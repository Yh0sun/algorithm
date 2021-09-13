#include<iostream>
using namespace std;

int main() {
	int numofpeople;
	int weight[50], high[50];
	int rank[50];

	cin >> numofpeople;
	
	for (int i = 0; i < numofpeople; i++) {
		rank[i] = 1;
	}

	for (int i = 0; i < numofpeople; i++) {
		cin >> weight[i] >> high[i];
	}

	for (int i = 0; i < numofpeople; i++) {
		for (int j = 0; j < numofpeople; j++) {
			if (weight[j] < weight[i] && high[j] < high[i]) {
				rank[j]++;
			}
			else continue;
		}
	}
	
	for (int k = 0; k < numofpeople; k++) {
					cout << rank[k] << " ";
	}
	
	return 0;
}