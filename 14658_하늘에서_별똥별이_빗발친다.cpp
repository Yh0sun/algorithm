#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	int height, width, trampolin, starNum;
	int x, y;
	cin >> height >> width >> trampolin >> starNum;

	set<int>table_x;
	set<int>table_y;
	vector<int> input_x;
	vector<int> input_y;
	int maxVal = -1;

	for (int i = 0; i < starNum; i++) {
		cin >> x >> y;
		input_x.push_back(x);
		input_y.push_back(y);
		table_x.insert(x);
		table_y.insert(y);
	}

	for (set<int>::iterator i = table_x.begin(); i != table_x.end(); ++i) {
		for (set<int>::iterator j = table_y.begin(); j != table_y.end(); ++j) {
			int cnt = 0;

			for (int k = 0; k < starNum; k++) {
				if (*i <= input_x[k] && input_x[k] <= *i + trampolin && *j <= input_y[k] && input_y[k] <= *j + trampolin)cnt++;
			}
			//cout << *i << *j << endl << cnt << endl;
			maxVal = max(maxVal, cnt);
		}
	}

	cout << starNum - maxVal;
	return 0;
}