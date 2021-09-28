#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	int num, weight;
	int max_weight = 0;
	int count = 0;
	
	cin >> num;

	int* arr = new int[num];

	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + num);

	for (int i = 0; i < num; i++) {
		weight = arr[i] * (num - i);
		if (weight > max_weight)max_weight = weight;
	}

	cout << max_weight;
	delete[] arr;
	return 0;
}