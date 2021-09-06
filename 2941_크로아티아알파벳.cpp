#include<iostream>
using namespace std;

int main() {
	 
	string cro;
	int sum = 0;

	cin >> cro;

	for (int i = 0; i < cro.size(); i++) {
		if (cro[i] == '=') { 
			if (cro[i - 1] == 'z' && cro[i - 2] == 'd') sum--;
			else continue;
		} 
		else if (cro[i] == '-') continue;
		else if (cro[i] == 'j' && cro[i - 1] == 'l')continue;
		else if (cro[i] == 'j' && cro[i - 1] == 'n')continue;
		else sum++;
	}

	cout << sum;
	return 0;
}