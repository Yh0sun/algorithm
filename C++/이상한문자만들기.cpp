#include <string>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    int blank = -1;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            blank = i;
            answer += " ";
        }
        else if ((i - blank) % 2 == 1)answer += toupper(s[i]);
        else answer += tolower(s[i]);
    }

    return answer;
}
