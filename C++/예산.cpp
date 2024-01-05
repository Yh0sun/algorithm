#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    int sum = 0;

    sort(d.begin(), d.end());
    for (int i = 0; i < d.size(); i++) {
        if (sum < budget) {
            sum += d[i];
            answer++;
            if (sum > budget) {
                answer--;
                break;
            }
        }
    }
    return answer;
}
