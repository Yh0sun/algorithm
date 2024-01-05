#include <iostream>
using namespace std;

int main() {
	int t, nation, flight;
	int depart, arrive;
	
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> nation >> flight;
		for (int j = 0; j < flight; j++) {
			cin >> depart >> arrive;
		}
		cout << nation - 1 << endl;
	}

	return 0;
}