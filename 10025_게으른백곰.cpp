#include<iostream>
using namespace std;

int arr[1000001];

int main() {
	int num, inputK;
	int maxSum = 0, maxPosition = 0, sum = 0;
	int ice, position;

	cin >> num >> inputK;

	for (int i = 0; i < num; i++) {
		cin >> ice >> position;
		arr[position] = ice;
		if (maxPosition < position)maxPosition = position;
	}
	
	for (int i = 0; i <= inputK * 2; i++) {
		sum += arr[i];
		if (maxSum < sum)maxSum = sum;
		if (i == 1000000)break;
	}

	if (inputK < maxPosition) {
		for (int i = 1; i <= maxPosition - inputK * 2; i++) {
			sum = sum - arr[i - 1] + arr[i + inputK * 2];
			if (maxSum < sum)maxSum = sum;
		}
	}
	
	cout << maxSum;
	return 0;
}
