#include <string>
#include <vector>
using namespace std;

int isRightString(string s) {
    int num = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(')num++;
        else num--;
     
        if (num < 0)return 0;
    }
    if (num == 0)return 1;
    return 0;
}
string stringTurn(string s) {
    string ans = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(')ans.push_back(')');
        else ans.push_back('(');
    }
    return ans;
}
string makeRegularString(string s) {
    string str;
    int num1 = 0;
    int num2 = 0;

    for (int i = 0; i < s.size(); i++) {
        str.push_back(s[i]);
        if (s[i] == '(')num1++;
        else num2++;
        
        if (num1 == num2)return str;
    }
}
string solution(string p) {

    if (p.empty() || isRightString(p)) return p;
    else {
        string u = makeRegularString(p);
        string v = p.substr(u.size());
       
        if (isRightString(u)) return u + solution(v);
        else return "(" + solution(v) + ")" + stringTurn(u.substr(1, u.size() - 2));
    }
}