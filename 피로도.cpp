#include <string>
#include <vector>

using namespace std;

vector<int> sqs;
int answer = -1;

void make_p(int n,int k, vector<int> &vt, vector<vector<int>> &dg);
int solution(int k, vector<vector<int>> dungeons) {
    
    vector<int> visited(dungeons.size() + 1);
    make_p(dungeons.size(), k, visited, dungeons);

    return answer;
}
void make_p(int n, int k, vector<int>& vt, vector<vector<int>>& dg) {
    for (int i = 0; i < n; i++) {
        if (vt[i] == 0) {
            sqs.push_back(i);
            vt[i] = 1;
            make_p(n, k, vt, dg);
            vt[sqs.back()] = 0;
            sqs.pop_back();
        }

        if (sqs.size() == n) {
            int j = 0;
            int stamina = k;
            for (; j < sqs.size(); j++) {
                int index = sqs[j];
                if (dg[index][0] <= stamina) stamina -= dg[index][1];
                else {
                    break;
                }
            }
            if (j > answer)answer = j;
            break;
        }
       
    }
}
