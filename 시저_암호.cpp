#include <string>

using namespace std;

string solution(string s, int n) {
    string answer = "";

     for (int i = 0; i < s.size(); i++) {
        if (s[i] > 64 && s[i] < 91) {
            int tmp = (int)s[i] + n;
            if (tmp > 90)tmp = 64 + (tmp - 90);
            answer += (char)tmp;
        }
        else if (s[i] > 96 && s[i] < 123) {
            int tmp = (int)s[i] + n;
            if (tmp > 122)tmp = 96 + (tmp - 122);
            answer += (char)tmp;
        }
        else
            answer += s[i];
    }


    return answer;
}
