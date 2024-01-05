#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> grid) {

    vector<int> answer;
    int x_size = grid.size();
    int y_size = grid[0].size();
    int history[5][500][500];

    for (int i = 0; i < x_size; i++) {
        for (int j = 0; j < y_size; j++) {

            for (int k = 0; k < 4; k++) {
                
                int dir = k;  //dir 0,1,2,3
                int x = i;
                int y = j;

                int cnt = 0;
               
                if (history[k][i][j] == 0) {
                    history[dir][x][y] ++;

                    do {
                        if (grid[x][y] == 'R')dir += 1;
                        else if (grid[x][y] == 'L')dir -= 1;
                        
                        if (dir < 0)dir = 3;
                        if (dir > 3)dir = 0;

                        if (dir == 0) x--;
                        else if (dir == 1) y++;
                        else if (dir == 2) x++;
                        else if (dir == 3) y--;

                        if (x == x_size)x = 0;
                        if (x < 0)x = x_size - 1;
                        if (y == y_size)y = 0;
                        if (y < 0)y = y_size - 1;

                        cnt++;
                        history[dir][x][y] ++;

                    } while (!(dir == k && x == i && y == j));

                    answer.push_back(cnt);
                }
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}
