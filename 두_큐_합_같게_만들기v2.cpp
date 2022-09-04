#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    int index1 = 0, index2 = 0;
    long long sum1 = 0, sum2 = 0;
    int s = queue1.size();

    for (int i = 0; i < queue1.size(); i++) {
        sum1 += queue1[i];
        sum2 += queue2[i];
    }

    while (true) {
        answer++;
        if (index1 > s && index2 > s)return -1;
        if (index1 == queue1.size() || index2 == queue2.size())return -1;
        if (sum1 == sum2) break;
        else if (sum1 > sum2) {
            sum2 += queue1[index1];
            sum1 -= queue1[index1];
            queue2.push_back(queue1[index1]);
            index1++;
        }
        else {
            sum1 += queue2[index2];
            sum2 -= queue2[index2];
            queue1.push_back(queue2[index2]);
            index2++;
        }
    }

    return answer;
}
