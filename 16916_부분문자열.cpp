#include <iostream>
#include <vector>
using namespace std;

int main() {

	bool answer = false;

	string str_s, str_p;
	cin >> str_s >> str_p;
	
	vector <int> pi(str_p.size(), 0);
	for (int i = 1; i < str_p.size(); i++) {
		string tmp = str_p.substr(0, i + 1);
		int cnt = 1;
		for (int j = i; j > 0; j--) {
			if (tmp.substr(0, cnt) == tmp.substr(i))pi[i] == cnt;
			cnt++;
		}
	}

	int j = 0;
	for (int i = 0; i < str_s.size();) {
		for (; j < str_p.size(); j++) {
			if (str_s[i + j] != str_p[j]) {
				if (j <= 1) {
					i++;
					break;
				}
				else {
					if (i + j - pi[j - 1] >= 0)i = i + j - pi[j - 1];
					else i++;

					j = pi[j - 1];

					break;
				}
			}

			if (j == str_p.size() - 1) answer = true;
			
		}
		if (answer)break;
	}

	cout << answer;
	return 0;
}
