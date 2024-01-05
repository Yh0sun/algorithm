#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] > 47 && s[i] < 58 || s[i] == ' ') {
            answer.push_back(s[i]);
            continue;
        }
        if (i == 0 || s[i - 1] == ' ') {
            answer.push_back(toupper(s[i]));
        }
        else answer.push_back(tolower(s[i]));
    }
    return answer;
}
