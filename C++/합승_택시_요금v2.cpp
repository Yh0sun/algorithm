#include <string>
#include <vector>
#include <queue>

#define INF 20000000
using namespace std;

int minDisToA[201] = { 0, };
int minDisToB[201] = { 0, };

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {

    int answer = INF;
    vector<vector<pair<int, int>>> path(n + 1);
    vector<int> startToN;
    
    for (int i = 0; i < fares.size(); i++) {
        path[fares[i][0]].push_back({ fares[i][2],fares[i][1] });
        path[fares[i][1]].push_back({ fares[i][2],fares[i][0] });
    }

    for (int i = 1; i <= n; i++) {
        vector<int> dis(n + 1, INF);
        priority_queue<pair<int, int>> pq;

        pq.push({ 0,i });
        dis[i] = 0;

        while (!pq.empty()) {
            int d = -pq.top().first;
            int nextN = pq.top().second;
            pq.pop();

            if (dis[nextN] < d)continue;
           
            for (int j = 0; j < path[nextN].size(); j++) {
                int _d = path[nextN][j].first;
                int _nextN = path[nextN][j].second;
                if (dis[_nextN] > d + _d) {
                    dis[_nextN] = d + _d;
                    pq.push({ -dis[_nextN] ,_nextN });
                }
            }
        }
        if (i == s) {
            for (int k = 1; k <= n; k++) {
                startToN = dis;
            }
        }
        minDisToA[i] = dis[a];
        minDisToB[i] = dis[b];
    }

    int tmp;
    for (int i = 1; i <= n; i++) {
        tmp = startToN[i] + minDisToA[i] + minDisToB[i];
        if (answer > tmp)answer = tmp;
    }

    return answer;
}
