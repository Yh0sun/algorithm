#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, answer = 0;
	int gap = 0;
	bool isHannum;
	string temp;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		temp = to_string(i);
		if (temp.size() != 1) {
			isHannum = true;
			gap = temp[0] - temp[1];
			for (int j = 0; j < temp.size() - 1; j++)
				if (gap != temp[j] - temp[j + 1]) {
					isHannum = false;
					break;
				}

			if (isHannum)answer++;
		}
		else answer++;
	}

	cout << answer;
	return 0;
}