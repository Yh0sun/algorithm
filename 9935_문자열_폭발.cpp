#include <iostream>
#include <string>
using namespace std;

int main() {
	string input, bomb, ans = "";
	cin >> input >> bomb;

	int bombLen = bomb.length();
	
	for (int i = 0; i < input.length(); i++) {
		ans.push_back(input[i]);
		bool flag = true;
		if (ans.length() >= bombLen) {
			for (int j = 0; j < bombLen; j++) {
				if (ans[ans.length() - 1 - j] != bomb[bombLen - 1 - j]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				for (int j = 0; j < bombLen; j++) {
					ans.pop_back();
				}
			}
		}
	}

	if (ans.empty())cout << "FRULA";
	else cout << ans;
	return 0;
}