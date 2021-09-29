#include<iostream>
using namespace std;

int main() {

	char input1, input2;
	int arr[6][6] = { 0 };
	int x, y, start_x, start_y, before_x = 0, before_y = 0;
	int point_one = 1, point_two = 1, point_three = 1;

	for (int i = 0; i < 36; i++) {
		cin >> input1 >> input2;
		x = input1 - 'A';
		y = input2 - '1';

		if (i == 0) {
			start_x = x;
			start_y = y;
		}

		arr[x][y] = 1;
	
		if (i != 0)
			if ((x - before_x) * (x - before_x) + (y - before_y) * (y - before_y) != 5)
				point_three = 0;

		before_x = x;
		before_y = y;

		if (i == 35)
			if ((x - start_x) * (x - start_x) + (y - start_y) * (y - start_y) != 5) 
				point_two = 0;
		
	}

	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++) 
			if (arr[i][j] == 0)point_one = 0;
		
	if (point_one == 1 && point_two == 1 && point_three == 1)
		cout << "Valid";
	else cout << "Invalid";

	return 0;
}