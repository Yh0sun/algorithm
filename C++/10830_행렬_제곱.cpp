#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> input_arr;

vector<vector<int>> multipe(vector<vector<int>> arr, bool flag) {

	vector<vector<int>> vec;
	for (int i = 0; i < n; i++) {
		vector<int> v;
		for (int j = 0; j < n; j++) {
			int sum = 0;
			for (int k = 0; k < n; k++) {
				sum += arr[i][k] * arr[k][j];
			}
			v.push_back(sum % 1000);
		}
		vec.push_back(v);
	}

	if (flag) {
		vector<vector<int>> true_vec;
		for (int i = 0; i < n; i++) {
			vector<int> v;
			for (int j = 0; j < n; j++) {
				int sum = 0;
				for (int k = 0; k < n; k++) {
					sum += vec[i][k] * input_arr[k][j];
				}
				v.push_back(sum % 1000);
			}
			true_vec.push_back(v);
		}
		return true_vec;
	}
	else return vec;
}

vector<vector<int>> func(long long cnt) {
	if (cnt == 1)return input_arr;
	if (cnt % 2 == 0)return multipe(func(cnt / 2), false);
	else return multipe(func(cnt / 2), true);
}

int main() {

	int tmp;
	long long b;
	cin >> n >> b;

	for (int i = 0; i < n; i++) {
		vector<int> v;
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			v.push_back(tmp);
		}
		input_arr.push_back(v);
	}

	vector<vector<int>> ans;
	ans = func(b);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", ans[i][j]%1000);
		}
		printf("\n");
	}
	return 0;
}
