#include <iostream>
#include <string>

using namespace std;

int button[10] = { 0, };
int channel, ans;

int check(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (button[str[i] - '0'] == 1)return 0;
	}
	cout << min(ans, (int)str.length());
	return 1;
}

int func(string btn) {
	if (btn!="") {
		int tmp = btn.length() + abs(channel - stoi(btn));
		if (tmp < ans)ans = tmp;
	}

	if (btn.length() == 7)return 0;

	for (int i = 0; i < 10; i++) {
		if (button[i] == 0) {
			func(btn + to_string(i));
		}
	}
	return 0;
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int brokenButtonNum, brokenButton;
	cin >> channel >> brokenButtonNum;
	
	for (int i = 0; i < brokenButtonNum; i++) {
		cin >> brokenButton;
		button[brokenButton] = 1;
	}
	ans = abs(channel - 100);
	if (check(to_string(channel))) return 0;
	
	func("");
	cout << ans;
	return 0;
}