#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

int N;
int sea[20][20] = { 0, };
int visited[20][20] = { 0, };
int bsS = 2;
int answer = 0;
int cnt = 0;
pair<int, int> point;

pair<int, int> findWay(pair<int, int>);
bool compare(pair<int, int> a, pair<int, int> b) {
   
    if (visited[a.first][a.second] == visited[b.first][b.second]) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        else return a.first < b.first;
    }
    else {
        return visited[a.first][a.second] < visited[b.first][b.second];
    }
}
int main() {


    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> sea[i][j];
            if (sea[i][j] == 9) {
                point = make_pair(i, j);
                sea[i][j] = 0;
            }
        }
    }

    while (true) {
        point = findWay(point);
        if (point == make_pair(-1, -1))break;
    }
    cout << answer;
    return 0;
}

pair<int, int> findWay(pair<int, int> a) {

    int dir[4][2] = { {-1,0},{0,-1},{0,1}, {1,0} };
    memset(visited, 0, sizeof(visited));
    queue< pair<int, int> > que;
    vector< pair<int, int>> fishs;

    que.push(a);
    visited[a.first][a.second] = 1;

    while (!que.empty()) {
        pair<int, int> curr = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int nx = curr.first + dir[i][0];
            int ny = curr.second + dir[i][1];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                if (visited[nx][ny] == 0 && sea[nx][ny] <= bsS) {
                    que.push(make_pair(nx, ny));
                    visited[nx][ny] = visited[curr.first][curr.second] + 1;
                    if (sea[nx][ny] < bsS && sea[nx][ny] != 0) {
                        fishs.push_back(make_pair(nx, ny));
                    }
                }
            }
        }
    }

    pair<int, int> next = make_pair(-1, -1);

    if (!fishs.empty()) {
        sort(fishs.begin(), fishs.end(), compare);
        next = fishs[0];
        sea[next.first][next.second] = 0;
        cnt++;
        if (cnt == bsS) {
            cnt = 0;
            bsS++;
        }
        answer += visited[next.first][next.second] - 1;
    }

    return  next;
}
