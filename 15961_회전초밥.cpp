#include<iostream>
using namespace std;

int arr[3000000] = { 0, };
int eat[3001] = { 0, };

int main() {
	int num, various, serial, cupon;
	
	int sum = 0;
	

	cin >> num >> various >> serial >> cupon;

	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}
	
	for (int i = 0; i < serial; i++) {
		eat[arr[i]]++;	
		if (eat[arr[i]] == 1)sum++;
	}

	if (eat[cupon] == 0) {
		eat[cupon] = 1;
		sum++;
	}
	else eat[cupon]++;
	int maxSum = sum;

	for (int j = 1; j < num  ; j++) {
		
		if (eat[arr[j - 1]] == 1) {
			eat[arr[j - 1]] = 0;
			sum--;
		}
		else eat[arr[j - 1]]--;

		int add = j + serial - 1;
		if (add >= num)add = add % num;

		if (eat[arr[add]] == 0) {
			eat[arr[add]] = 1;
			sum++;
		}
		else eat[arr[add]]++;

		if (maxSum < sum) maxSum = sum;
	}

	cout << maxSum;
	return 0;
}
