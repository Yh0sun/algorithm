#include <string>
#include <vector>
#include <queue>

#define INF 20000000
using namespace std;
vector<vector<int>> dis;

void dx(int start, int n, vector<vector<pair<int, int>>> &path) {
    vector<int> Ndis(n + 1, INF);
    priority_queue<pair<int, int>> pq;

    pq.push({ 0,start });
    Ndis[start] = 0;

    while (!pq.empty()) {
        int d = -pq.top().first;
        int nextN = pq.top().second;
        pq.pop();

        if (Ndis[nextN] < d)continue;
     
        for (int j = 0; j < path[nextN].size(); j++) {
            int _d = path[nextN][j].first;
            int _nextN = path[nextN][j].second;
           
            if (Ndis[_nextN] > d + _d) {
                Ndis[_nextN] = d + _d;
                pq.push({ -Ndis[_nextN] ,_nextN });   
            }
        }
    }
    dis.push_back(Ndis);
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {

    int answer = INF;
    vector<vector<pair<int, int>>> path(n + 1);

    for (int i = 0; i < fares.size(); i++) {
        path[fares[i][0]].push_back({ fares[i][2],fares[i][1] });
        path[fares[i][1]].push_back({ fares[i][2],fares[i][0] });
    }
    dis.push_back(vector<int>());
    for (int i = 1; i <= n; i++) {
        dx(i, n, path);
    }

    int tmp;
    for (int i = 1; i <= n; i++) {
        tmp = dis[s][i] + dis[i][a] + dis[i][b];
        if (answer > tmp)answer = tmp;
    }

    return answer;
}
