#include <stack>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> finishDay;
    vector<int> vec;

    for (int i = 0; i < progresses.size(); i++) {
        int day = (100 - progresses[i]) / speeds[i];
        if ((100 - progresses[i]) % speeds[i] != 0)day++;
        finishDay.push_back(day);
    }

    int release = finishDay[0];
    vec.push_back(finishDay[0]);
    for (int i = 1; i < progresses.size(); i++) {
        if (release < finishDay[i]) {
            answer.push_back(vec.size());
            release = finishDay[i];
            vec.clear();
            vec.push_back(finishDay[i]);
        }
        else {
            vec.push_back(finishDay[i]);
        }
    }
    if (!vec.empty())answer.push_back(vec.size());
    return answer;
}