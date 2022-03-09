#include<iostream>
#include<set>
using namespace std;

int main() {
	int num, various, serial, cupon;
	int arr[30001];
	int maxSum = 0;

	cin >> num >> various >> serial >> cupon;

	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}

	for (int j = 0; j < num; j++) {
		set<int> eat;
		int sum;
		for (int k = j; k < j + serial; k++) {
			int th = k;
			if (k >= num) th = k % num;
			eat.insert(arr[th]);
		}
		sum = eat.size();
		if (eat.find(cupon) == eat.end())sum++;

		if (maxSum < sum)maxSum = sum;
	}

	cout << maxSum;
	return 0;
}
