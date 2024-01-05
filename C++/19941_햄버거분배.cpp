#include<iostream>
using namespace std;
string hp;
int interval;
bool eat(int i) {
	bool sucess = false;

	for (int k = interval; k > 0; k--) {
		if (hp[i - k] == 'H') {
			sucess = true;
			hp.replace(i - k, 1, ".");
			break;
		}	
	}
	if (!sucess) {
		for (int k = 1; k <= interval; k++) {
			if (hp[i + k] == 'H') {
				sucess = true;
				hp.replace(i + k, 1, ".");
				break;
			}
		}
	}
	return sucess;
};

int main() {
	int num, result = 0;

	cin >> num >> interval >> hp;

	for (int i = 0; i < num; i++) {
		if (hp[i] == 'P') {
			if (eat(i))result++;
		}
	}

	cout << result;
	
	return 0;
}