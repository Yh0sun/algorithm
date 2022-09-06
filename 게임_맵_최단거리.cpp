#include<vector>
#include<queue>

using namespace std;

int dir_x[4] = { 1,0,-1,0 };
int dir_y[4] = { 0,1,0,-1 };

int solution(vector<vector<int> > maps)
{
    queue<pair<int, int>> que;
    int x_size = maps.size();
    int y_size = maps[0].size();
    vector<vector<int>> visited(x_size,vector<int>(y_size,0));

    que.push({ 0,0 });
    visited[0][0] = 1;

    while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dir_x[i];
            int ny = y + dir_y[i];

            if (nx >= 0 && nx < x_size && ny >= 0 && ny < y_size) {
                if (maps[nx][ny] == 1 && visited[nx][ny] == 0) {
                    visited[nx][ny] = visited[x][y] + 1;
                    que.push({ nx,ny });
                    if (nx == x_size - 1 && ny == y_size - 1) {
                        return visited[nx][ny];
                    }                   
                }
            }
        }
    }
    return -1;
}
