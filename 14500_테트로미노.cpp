#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[500][500];

int tetromino1(int i, int j) {
	int max_sum = 0;
	int sum = 0;

	if (j + 3 < m) {
		for (int k = 0; k < 4; k++) {
			sum += arr[i][j + k];
		}
	}
	if (max_sum < sum)max_sum = sum;
	sum = 0;

	if (i + 3 < n) {
		for (int k = 0; k < 4; k++) {
			sum += arr[i + k][j];
		}
	}
	if (max_sum < sum)max_sum = sum;
	return max_sum;
}
int tetromino2(int i, int j) {
	int sum = 0;
	if (i + 1 < n && j + 1 < m) 
		sum = arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1];	
	return sum;
}
int tetromino3(int i, int j) {
	int max_sum = 0;
	int sum = 0;
	int form = 0;

	if (j + 2 < m) {
		for (int k = 0; k < 3; k++) {
			form += arr[i][j + k];
		}
		if (i - 1 >= 0) {
			if (arr[i - 1][j + 2] > arr[i - 1][j])
				sum = form + arr[i - 1][j + 2];
			else
				sum = form + arr[i - 1][j];
		}
		if (max_sum < sum)max_sum = sum;
		if (i + 1 < n) {
			if (arr[i + 1][j + 2] > arr[i + 1][j])
				sum = form + arr[i + 1][j + 2];
			else
				sum = form + arr[i + 1][j];
		}
		if (max_sum < sum)max_sum = sum;
	}
	
	sum = 0;
	form = 0;

	if (i + 2 < n) {
		for (int k = 0; k < 3; k++) {
			form += arr[i + k][j];
		}
		if (j - 1 >= 0) {
			if (arr[i][j - 1] > arr[i + 2][j - 1])
				sum = form + arr[i][j - 1];
			else
				sum = form + arr[i + 2][j - 1];
		}
		if (max_sum < sum)max_sum = sum;
		if (j + 1 < m) {
			if (arr[i][j + 1] > arr[i + 2][j + 1])
				sum = form + arr[i][j + 1];
			else
				sum = form + arr[i + 2][j + 1];
		}
		if (max_sum < sum)max_sum = sum;
	}
	return max_sum;
}
int tetromino4(int i, int j) {
	int max_sum = 0;
	int sum = 0;
	int form = 0;

	if (j + 1 < m) {
		for (int k = 0; k < 2; k++) {
			form += arr[i][j + k];
		}

		if (i - 1 >= 0) {
			if (j + 2 < m) {
				sum = form + arr[i - 1][j + 1] + arr[i - 1][j + 2];
				if (max_sum < sum)max_sum = sum;
			}
			if (j - 1 >= 0) {
				sum = form + arr[i - 1][j] + arr[i - 1][j - 1];
				if (max_sum < sum)max_sum = sum;
			}
		}
	}

	sum = 0;
	form = 0;

	if (i + 1 < n) {
		for (int k = 0; k < 2; k++) {
			form += arr[i + k][j];
		}

		if (i - 1 >= 0) {
			if (j + 1 < m) {
				sum = form + arr[i][j + 1] + arr[i - 1][j + 1];
				if (max_sum < sum)max_sum = sum;
			}
			if (j - 1 >= 0) {
				sum = form + arr[i][j - 1] + arr[i - 1][j - 1];
				if (max_sum < sum)max_sum = sum;
			}
		}
	}
	return max_sum;
}
int tetromino5(int i, int j) {
	int max_sum = 0;
	int sum = 0;
	int form = 0;

	if (j + 2 < m) {
		for (int k = 0; k < 3; k++) {
			form += arr[i][j + k];
		}

		if (i - 1 >= 0) {
			sum = form + arr[i - 1][j + 1];
			if (max_sum < sum)max_sum = sum;
		}
		if (i + 1 < m) {
			sum = form + arr[i + 1][j + 1];
			if (max_sum < sum)max_sum = sum;
		}
	}

	sum = 0;
	form = 0;

	if (i + 2 < n) {
		for (int k = 0; k < 3; k++) {
			form += arr[i + k][j];
		}

		if (j - 1 >= 0) {
			sum = form + arr[i + 1][j - 1];
			if (max_sum < sum)max_sum = sum;
		}
		if (j + 1 < m) {
			sum = form + arr[i + 1][j + 1];
			if (max_sum < sum)max_sum = sum;
		}
	}
	return max_sum;
}

int main() {

	int max_te = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int te[5] = { tetromino1(i,j), tetromino2(i, j), tetromino3(i, j), tetromino4(i, j), tetromino5(i, j) };
			int max = *max_element(te, te + 5);
			if (max_te < max)max_te = max;
		}
	}
	
	cout << max_te;

	return 0;
}
