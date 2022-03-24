#include <string>
#include <vector>

using namespace std;

bool correct_bracket(string ss);
int solution(string s) {
    int answer = 0;
    if (correct_bracket(s))answer++;

    for (int i = 1; i < s.size(); i++) {
        s.push_back(s.front());
        s = s.substr(1);

        if (correct_bracket(s))answer++;
    }

    return answer;
}
bool correct_bracket(string ss) {

    vector<char> v;

    for (int i = 0; i < ss.size(); i++) {
        if (ss[i] == '{' || ss[i] == '[' || ss[i] == '(') 
            v.push_back(ss[i]);
        else {
            if (v.empty()) return false;
            else {
                if (v.back() == ss[i] - 2) v.pop_back();
                else if (v.back() == ss[i] - 1) v.pop_back();
                else return false; 
            }
        }
    }
    if (!v.empty())return false;

    return true;
}
