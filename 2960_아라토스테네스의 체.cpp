#include <iostream>

using namespace std;

int arr[1001];
int cnt = 0;
int n, qjsWo;

void removeMul(int p) {
	
	for (int j = 1;; j++) {
		if (p * j > n)break;
		
		if (arr[p * j] != 0) {
			arr[p * j] = 0;
			cnt++;
		}
		
		if (cnt == qjsWo) {
			cout << p * j;
			break;
		}
	}
}

int main() {

	cin >> n >> qjsWo;
	
	for (int i = 2; i <= n; i++) {
		arr[i] = i;
	}

	for (int i = 2; i <= n; i++) {
		if (arr[i] != 0) {
			removeMul(i);
		}
	}

	return 0;
}