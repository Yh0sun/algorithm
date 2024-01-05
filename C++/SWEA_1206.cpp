#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int num;
		int building[1000] = { 0, };
		int result = 0;
		cin >> num;

		for (int i = 0; i < num; i++) {
			cin >> building[i];
		}

		for (int i = 2; i < num - 2; i++) {
			vector<int> v;
			if (building[i - 1] < building[i] && building[i - 2] < building[i] && building[i + 1] < building[i] && building[i + 2] < building[i]) {
				v.push_back(building[i - 1]);
				v.push_back(building[i - 2]);
				v.push_back(building[i + 1]);
				v.push_back(building[i + 2]);
				int m = *max_element(v.begin(), v.end());
				result += building[i] - m;
			}
		}

		cout << "#" << test_case << " " << result << endl;
	}
	return 0;
}
