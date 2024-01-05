#include <iostream>
using namespace std;

long long pinaryNum[91] = { 0, };

long long findPinaryNum(int num) {
	if (num < 2)return pinaryNum[num] = 1;
	findPinaryNum(num - 1);
	return pinaryNum[num] = pinaryNum[num - 1]+ pinaryNum[num - 2];
}

int main() {
	int n;
	cin >> n;

	findPinaryNum(n);
	cout<< pinaryNum[n];

	return 0;
}
