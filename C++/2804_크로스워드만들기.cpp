#include<iostream>
#include<string.h>
using namespace std;

int main() {

	string inputA, inputB;
	int n, m;
	int A_result = 0, B_result = 0, count = 0;

	cin >> inputA >> inputB;

	n = inputA.size();
	m = inputB.size();

	char** arr = new char* [m];

	for (int i = 0; i < m; i++) {
		arr[i] = new char[n];
		memset(arr[i], '.', sizeof(char) * n);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (inputA[i] == inputB[j]) {
				A_result = i;
				B_result = j;
				count++;
				break;
			}

		}
		if (count == 1)break;

	}


	for (int i = 0; i < m; i++)
		arr[i][A_result] = inputB[i];

	for (int i = 0; i < n; i++)
		arr[B_result][i] = inputA[i];

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << arr[i][j];
		cout << endl;
	}

	for (int i = 0; i < m; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}