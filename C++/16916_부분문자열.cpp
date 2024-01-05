#include <iostream>
#include <vector>
using namespace std;

int main() {

	string str_s, str_p;
	cin >> str_s >> str_p;

	vector <int> pi(str_p.size());
	
	
	for (int i = 1, j = 0; i < str_p.size();) {

		if (str_p[j] == str_p[i]) {
			pi[i] = ++j;
			i++;
		}
		else {
			if (j == 0)i++;
			while (j > 0 && str_p[j] != str_p[i]) {
				j = pi[j - 1];
			}
		}
	}

	int b = 0;
	for (int a = 0; a < str_s.size();) {
		if (str_s[a] == str_p[b]) {
			if (b == str_p.size() - 1) {
				cout << "1";
				return 0;
			}
			a++;
			b++;
		}
		else {
			if (b == 0)a++;
			while (b > 0 && str_s[a] != str_p[b]) {
				b = pi[b - 1];
			}
		}
	}

	cout << "0";
	return 0;
}
