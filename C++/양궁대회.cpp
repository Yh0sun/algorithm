#include <string>
#include <vector>

using namespace std;

vector<int> answer;
int max_num = 0;

int find_score(int i, int left_arrow,int apeach_score, int lion_score, vector<int> score_list, vector<int>& info) {
   
    if (i == 11) {
        if (left_arrow == 0) {
            if (max_num < lion_score - apeach_score) {
                max_num = lion_score - apeach_score;
                answer = score_list;               
            }
            else if (max_num!=0&&max_num == lion_score - apeach_score) {
                for (int i = 10; i > -1; i--) {
                    if (answer[i] == 0 && score_list[i] == 0) continue;
                    if (answer[i] < score_list[i]) answer = score_list;
                    else break;
                }
            }
        }
        return 0;
    }   
  
    if (info[i] > 0)apeach_score += 10 - i;
    score_list.push_back(0);
    find_score(i + 1, left_arrow, apeach_score, lion_score, score_list, info);
    if (info[i] > 0)apeach_score -= 10 - i;
    score_list.pop_back();

    if (left_arrow > info[i]) {
        lion_score += 10 - i;
        left_arrow -= info[i] + 1;
        score_list.push_back(info[i] + 1);
        find_score(i + 1, left_arrow, apeach_score, lion_score, score_list, info);
    } 
    else {
        if (i == 10&&left_arrow!=0) {
            score_list.push_back(left_arrow);
            left_arrow = 0;
            find_score(i + 1, left_arrow, apeach_score, lion_score, score_list, info);
        }
    }
    return 0;
}

vector<int> solution(int n, vector<int> info) {
    vector<int> score_list;
    int  apeach_score = 0, lion_score = 0;
   
    find_score(0, n, apeach_score, lion_score, score_list, info);

    if (answer.size() == 0)return { -1 };
    return answer;
}
