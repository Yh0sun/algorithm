#include<iostream>
#include<string>
using namespace std;

int main() {

	int r = 0, c = 0, column = 0, row = 0, index = 0;
	string input;

	cin >> input;

	for (int i = 1; i <= input.size(); i++) {
		if (input.size() % i == 0) {
			r = i;
			c = input.size() / i;
		}
		if (column < r && (r <= c)) {
			column = r;
			row = c;
		}				
	}

	char** arr = new char* [column];

	for (int i = 0; i < column; i++) {
		arr[i] = new char[row];
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			arr[j][i] = input[index];
			index++;
		}
	}

	for (int i = 0; i < column; i++) {
		for (int j = 0; j < row; j++) {
			cout << arr[i][j];
		}
	}

	for (int i = 0; i < column; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	
	return 0;
}