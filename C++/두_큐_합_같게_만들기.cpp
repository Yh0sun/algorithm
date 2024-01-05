#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    long long sum1 = 0, sum2 = 0;
    vector<int> que1 = queue1;
    vector<int> que2 = queue2;

    for (int i = 0; i < queue1.size(); i++) {
        sum1 += que1[i];
        sum2 += que2[i];
    }

    while (true) {
        answer++;
        if (que1.size() == 0 || que2.size() == 0)return -1;
        if (sum1 == sum2) break;
        else if (sum1 > sum2) {
            sum2 += que1.front();
            sum1 -= que1.front();
            queue2.push_back(que1.front());
            que1.erase(que1.begin());
        }
        else {
            sum1 += que2.front();
            sum2 -= que2.front();
            que1.push_back(que2.front());
            que2.erase(que2.begin());
        }
        if (que1 == queue1 || que1 == queue2)return -1;
    }

    return answer;
}