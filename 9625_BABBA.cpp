#include<iostream>
using namespace std;

int main() {
	int inputK, resultA, resultB;
	int arr[46] = { 0,1,1, };
	
	cin >> inputK;

	for (int i = 3; i <= inputK; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	resultB = arr[inputK];
	resultA = arr[inputK - 1];
	
	cout << resultA << " " << resultB;
	return 0;
}