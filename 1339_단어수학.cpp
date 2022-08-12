#include <iostream>
#include <vector>

using namespace std;

int max_result = 0;
vector<int> check(26);
vector<char> alphabet;
int pp(vector<char>& ap, vector<int>& visited, vector<string>& str);
int cal(vector<char>& ap, vector<string>& str);

int main() {
	int num;
	cin >> num;

	vector<string> str(num);
	for (int i = 0; i < num; i++) {
		cin >> str[i];
		for (size_t j = 0; j < str[i].size(); j++) {
			int tmp = str[i][j] - 65;
			if (check[tmp] == 0) {
				alphabet.push_back(str[i][j]);
				check[tmp] = 1;
			}
		}
	}

	vector<char> ap;
	vector<int> visited(alphabet.size());
	pp(ap, visited, str);

	cout << max_result;
	return 0;
}
int pp(vector<char>& ap, vector<int>& visited, vector<string>& str) {

	for (size_t i = 0; i < alphabet.size(); i++) {
		if (visited[i] == 0) {
			ap.push_back(alphabet[i]);
			visited[i] = 1;
			if (ap.size() == alphabet.size()) {
				int re = cal(ap, str);
				if (re > max_result)max_result = re;
			}
			else pp(ap, visited, str);
			visited[i] = 0;
			ap.pop_back();
		}
	}
	return 0;
}
int cal(vector<char>& ap, vector<string>& str) {

	int n = 9;
	int sum = 0;

	for (size_t i = 0; i < ap.size(); i++)
		check[ap[i] - 65] = n--;

	for (size_t i = 0; i < str.size(); i++) {
		int num = 0;
		for (size_t j = 0; j < str[i].size(); j++) {
			num *= 10;
			num += check[str[i][j] - 65];
		}
		sum += num;
	}
	return sum;
}
