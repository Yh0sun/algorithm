#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> sudoku(9, vector<int>(9));
vector<vector<int>> ans;
vector<pair<int, int>> blank_list;
int horizontal_check[9][10] = { 0, };
int vertical_check[9][10] = { 0, };
int square_check[9][10] = { 0, };

int fill_in_the_blank(int blank_idx) {

	if (blank_idx >= blank_list.size()) {
		ans = sudoku;
		return 1;
	}
    
	int i = blank_list[blank_idx].first;
	int j = blank_list[blank_idx].second;

	for (int k = 1; k < 10; k++) {
		if (horizontal_check[i][k] == 0 && vertical_check[j][k] == 0 && square_check[(i / 3) * 3 + j / 3][k] == 0) {
			sudoku[i][j] = k;
			horizontal_check[i][k] = 1;
			vertical_check[j][k] = 1;
			square_check[(i / 3) * 3 + j / 3][k] = 1;

			if(fill_in_the_blank(blank_idx + 1))return 1;
			
			sudoku[i][j] = 0;
			horizontal_check[i][k] = 0;
			vertical_check[j][k] = 0;
			square_check[(i / 3) * 3 + j / 3][k] = 0;
		}
	}

	return 0;
}


int main() {

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];

			if (sudoku[i][j] == 0) {
				blank_list.push_back(make_pair(i, j));
				continue;
			}
			horizontal_check[i][sudoku[i][j]] = 1;
			vertical_check[j][sudoku[i][j]] = 1;
			square_check[(i / 3) * 3 + j / 3][sudoku[i][j]] = 1;
		}
	}

	fill_in_the_blank(0);
	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}