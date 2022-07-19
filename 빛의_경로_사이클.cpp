#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int history[5][500][500];
int x_size, y_size;

class mirror {
public:
    int dir = 0;
    int x = 0;
    int y = 0;
public:
    void set(int d, int i, int j) {
        dir = d;
        x = i;
        y = j;
    }
    vector<int> get() {
        return { dir,x,y };
    }
    void move(char g) {
        if (g == 'R') {
            dir -= 1;
        }
        else if (g == 'L') {
            dir += 1;
        }
        else {
            dir += 2;
        }
        if (dir > 4)dir -= 4;
        if (dir == 0)dir = 4;

        switch (dir)
        {
        case 1:
            x--;
            break;
        case 2:
            y++;
            break;
        case 3:
            x++;
            break;
        case 4:
            y--;
            break;
        default:
            break;
        }
        if (x == x_size)x = 0;
        if (x < 0)x = x_size - 1;
        if (y == y_size)y = 0;
        if (y < 0)y = y_size - 1;

        dir += 2;
        if (dir > 4)dir -= 4;
    }

};

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    x_size = grid.size();
    y_size = grid[0].size();
    
     for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
           
            for (int k = 1; k < 5; k++) {
                mirror tmp;
                int cnt = 0;
                vector<int> v = { k,i,j };
                tmp.set(k, i, j);
                history[k][i][j] = 1;
                int x = i;
                int y = j;
                do {
                    tmp.move(grid[x][y]);
                    x = tmp.x;
                    y = tmp.y;
                    cnt++;
                    history[tmp.dir][tmp.x][tmp.y] ++;
                } while (history[tmp.dir][tmp.x][tmp.y] < 2&&
                    tmp.get() != v);

                if (tmp.get() == v) {
                    answer.push_back(cnt);
                }
            }
        }
    }
    sort(answer.begin(), answer.end());

    return answer;
}
