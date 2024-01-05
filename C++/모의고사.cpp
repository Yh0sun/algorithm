#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int giveUp1[5] = { 1,2,3,4,5 };
    int giveUp2[8] = { 2,1,2,3,2,4,2,5 };
    int giveUp3[10] = { 3,3,1,1,2,2,4,4,5,5 };
    int score[3] = { 0, };

    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == giveUp1[i % 5]) score[0]++;
        if (answers[i] == giveUp2[i % 8]) score[1]++;
        if (answers[i] == giveUp3[i % 10]) score[2]++;
    }
    
    int _max = *max_element(score, score + 3);
    for (int z = 0; z < 3; z++) {
        if (_max == score[z]) answer.push_back(z + 1);
    }
    return answer;
}