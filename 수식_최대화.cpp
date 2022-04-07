#include <string>
#include <vector>
#include <iostream>
#include <regex>
using namespace std;

string cal(int n1, int n2, char c) {
    switch (c) {
    case '-':
        return "(" + to_string(n1 - n2) + ")";
    case '+':
        return "(" + to_string(n1 + n2) + ")";
    case '*':
        return "(" + to_string(n1 * n2) + ")";
    default:
        break;
    }
};
int main() {
    long long answer = 0;
    string expression = "100-200*300-500+20";

    string s = "(\(-)?\(?\d{1,3}\)?";
    vector<string> op = {
        {"-+*"},
        {"-*+"},
        {"+-*"},
        {"+*-"},
        {"*-+"},
        {"*+-"},
    };
    cout << "ok1";
    for (int i = 0; i < 6; i++) {
        string exp(expression);
        for (int j = 0; j < 3; j++) { 
            cout << "ok2";
            cout << s + "\\" + op[i][j] + s;
            regex r(s + "\\" + op[i][j] + s);
            smatch m;
            cout << "ok3";
            while (regex_match(exp, m, r)) {
                string str = m.str();
                cout << m.str() << endl;
                if (str.front() == '(') {
                    str.substr(1);
                    str.substr(0, str.size() - 1);
                }
                int num1 = stoi(str.substr(0, str.find(op[i][j])));
                int num2 = stoi(str.substr(str.find(op[i][j]) + 1));
                cout << num1 << num2 << cal(num1, num2, op[i][j])<< endl;
                exp.replace(exp.find(str), str.size(), cal(num1, num2, op[i][j]));
                cout << "ok";
            }
        }
        answer = max(answer, abs(stoll(exp)));
    }
    cout << answer;
    return 0;
}
