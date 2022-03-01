#include <iostream>
using namespace std;

void division(int a, int b);
int cut = 0;
int main() {
	int sausage, peo;
	
	cin >> sausage >> peo;

	cout << cut;
	return 0;
}

void division(int p, int s) {

	if (s / p < 1) {
		int remain = p % s;
		if (remain != 0) {
			cut += (p / s) * s;
			if ((s - remain) > remain) {
				if (remain % (s % remain) != 0) {
					cut += remain / (s % remain)*
				}
				else {
					cut += (remain / (s % remain) - 1)*
				}
			}
			else {
				cut += s - remain;
			}
		}
		else cut += (p / s - 1) * s;
	}
}
