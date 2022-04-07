#include <string>
#include <vector>
#include <regex>

using namespace std;

vector<string> op = {
       {"-+*"},
       {"-*+"},
       {"+-*"},
       {"+*-"},
       {"*-+"},
       {"*+-"},
};

string cal(string str,char c) {

    string num[3];
    regex rr(R"((\(?-?\d{1,}\)?)[-\+\*](\(?-?\d{1,}\)?))");
    smatch sm;

    if (regex_match(str, sm, rr)) { 
        for (int i = 1; i < sm.size(); i++) {           
            num[i] = sm[i].str();
            if (num[i].find("(") != string::npos) {
                num[i] = num[i].substr(1, num[i].size() - 2);
            }
        }
    }

    switch (c) {
    case '-':
        return "(" + to_string(stoll(num[1]) - stoll(num[2])) + ")";
    case '+':
        return "(" + to_string(stoll(num[1]) + stoll(num[2])) + ")";
    case '*':
        return "(" + to_string(stoll(num[1]) * stoll(num[2])) + ")";
    default:
        break;
    }
};

long long solution(string expression) {
    long long answer = 0;
     string s = "(\\(-)?\\(?\\d{1,}\\)?";

    for (int i = 0; i < 6; i++) {
        string exp(expression);
        for (int j = 0; j < 3; j++) { 
            regex r(s + "\\" + op[i][j] + s);
            smatch m;
            while (regex_search(exp, m, r)) {
                exp.replace(exp.find(m.str()), m.str().size(), cal(m.str(),op[i][j]));
            }           
        }
        exp = exp.substr(1, exp.size() - 2);
        answer = max(answer, abs(stoll(exp)));

    }
    return answer;
}
