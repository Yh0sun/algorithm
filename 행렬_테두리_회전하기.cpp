#include <string>
#include <vector>

using namespace std;

int table[100][100] = { 0, };
void setting(int r, int c) {
    int num = 1;
    for (int i = 0; i < r; i++) 
        for (int j = 0; j < c; j++) 
            table[i][j] = num++;
}
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    setting(rows, columns);

    for (int i = 0; i < queries.size(); i++) {
        int min_val = 10001;
        int x_size = queries[i][2] - queries[i][0];
        int y_size = queries[i][3] - queries[i][1];
        int x = queries[i][0] - 1, y = queries[i][1] - 1;
        int val = table[x][y];

        for (int j = 0; j < y_size; j++) {
            swap(val, table[x][++y]);
            if (min_val > val)min_val = val;
        }
        for (int j = 0; j < x_size; j++) {
            swap(val, table[++x][y]);
            if (min_val > val)min_val = val;
        }
        for (int j = 0; j < y_size; j++) {
            swap(val, table[x][--y]);
            if (min_val > val)min_val = val;
        }
        for (int j = 0; j < x_size; j++) {
            swap(val, table[--x][y]);
            if (min_val > val)min_val = val;
        }
        answer.push_back(min_val);
    }
    return answer;
}