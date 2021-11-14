#include<iostream>
using namespace std;

int main() {
	int num, sum = 0;
	int arr[101][2] = { 0, };
	
	cin >> num;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < num; i++) 
		for (int j = i + 1; j < num; j++) 
			if (arr[i][0] > arr[j][0]) {
				int tmp = arr[i][0];
				arr[i][0] = arr[j][0];
				arr[j][0] = tmp;
				tmp = arr[i][1];
				arr[i][1] = arr[j][1];
				arr[j][1] = tmp;
			}
	
	for (int k = 0; k < num; k++) {
		if (arr[k][0] <= sum)sum += arr[k][1];
		else sum = arr[k][0] + arr[k][1];
	}

	cout << sum;
	return 0;
}