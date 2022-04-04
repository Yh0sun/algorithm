#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<string> p;
bool check_rule(int j, int k);

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (int i = 0; i < places.size(); i++) {
        p = places[i];

        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (p[j][k] == 'P' && !check_rule(j, k)){
                    answer.push_back(0);
                    break;
                }
            }
            if (answer.size() == i + 1)break;
        }
        p.clear();
        if (answer.size() != i + 1)answer.push_back(1);
    }
    return answer;
}
bool check_rule(int j, int k) {
    int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
    int visited[5][5] = { 0, };
    queue <pair<int, int>> que;

    que.push(make_pair(j, k));
    visited[j][k] = 1;

    while (!que.empty()) {
        pair<int, int> curr = que.front();
        que.pop();

        if (visited[curr.first][curr.second] >= 3) break;

        for (int i = 0; i < 4; i++) {
            int nx = curr.first + dir[i][0];
            int ny = curr.second + dir[i][1];
            if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
                if (visited[nx][ny] == 0 && p[nx][ny] != 'X') {
                    que.push({ nx,ny });
                    visited[nx][ny] = visited[curr.first][curr.second] + 1;
                    if (p[nx][ny] == 'P') return false;
                }
            }
        }
    }
    return true;
}
