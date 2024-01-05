#include <iostream>
#include <queue>

using namespace std;

int input[300][300] = { 0, };
int output[300][300] = { 0, };

int main() {
	int N, M, rotate;

	cin >> N >> M >> rotate;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> input[i][j];
		}
	}

	double num = N > M ? (double)M / 2.0 : (double)N / 2.0;
	for (int i = 0; i < num; i++) {
		int ro = rotate;
		queue<int> que;
		for (int j = i; j < M - i; j++) {
			que.push(input[i][j]);
		}
		for (int j = i + 1; j < N - i; j++) {
			que.push(input[j][M - i - 1]);
		}
		for (int j = M - i - 2; j >= i; j--) {
			que.push(input[N - i - 1][j]);
		}
		for (int j = N - 2 - i; j > i; j--) {
			que.push(input[j][i]);
		}

		if (rotate >= que.size())ro = rotate % que.size();

		for (int k = 0; k < ro; k++) {
			que.push(que.front());
			que.pop();
		}

		for (int j = i; j < M - i; j++) {
			output[i][j] = que.front();
			que.pop();
		}
		for (int j = i + 1; j < N - i; j++) {
			output[j][M - i - 1] = que.front();
			que.pop();
		}
		for (int j = M - i - 2; j >= i; j--) {
			output[N - i - 1][j] = que.front();
			que.pop();
		}
		for (int j = N - 2 - i; j > i; j--) {
			output[j][i] = que.front();
			que.pop();
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << output[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
