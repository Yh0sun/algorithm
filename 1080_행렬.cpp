#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> input;
void change(int i, int j);

int main() {
	int N, M, result = 0;
	vector<string> output;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		input.push_back(str);
	}

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		output.push_back(str);
	}
	
	if (input == output) {
		cout << "0";
		return 0;
	}

	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 2; j++) {
			if (input[i][j] != output[i][j]) {
				change(i, j);
				result++;
			}
			if (input == output) {
				cout << result;
				return 0;
			}
		}
	}

	cout << "-1";
	return 0;
}
void change(int i,int j) {
	
	for (int a = i; a < i + 3; a++) {
		for (int b = j; b < j + 3; b++) {
			if (input[a][b] == '0')input[a][b] = '1';
			else input[a][b] = '0';
		}
	}

}
