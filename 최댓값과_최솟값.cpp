#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    string str = "";
    int max_val = -10000000;
    int min_val = 10000000;

    for (int i = 0; i <= s.size(); i++) {
        if (i == s.size() || s[i] == ' ') {
            if (stoi(str) > max_val)max_val = stoi(str);
            if (stoi(str) < min_val)min_val = stoi(str);
            str = "";
            continue;
        }
        str.push_back(s[i]);
    }

    answer = to_string(min_val) + " " + to_string(max_val);
    return answer;
}