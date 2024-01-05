#include <iostream>
#include <cmath>

using namespace std;

int hanoi(int n, int from, int to,int r) {
	if (n == 1) {
		cout << from << " " << to << "\n";      //endl 를 쓰면 시간초과!!
		return 0;				//scanf, printf를 쓰면 더 빠른다.
	}

	hanoi(n - 1, from, r, to);
	cout << from << " " << to << "\n";
	hanoi(n - 1, r, to, from);
	
	return 0;
}

int main() {
	int num;

	cin >> num;
	cout << (int)pow(2, num) - 1 << "\n";	//pow 는 double로 return

	hanoi(num, 1, 3, 2);

	return 0;
}
