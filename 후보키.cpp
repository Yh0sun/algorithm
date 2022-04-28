#include <string>
#include <vector>
#include <set>

using namespace std;

string index;
vector<string> history;

void choose(int c, int t, vector<vector<string>> &r);
void isKey(vector<vector<string>>& r);
bool check(string);

int solution(vector<vector<string>> relation) {

    for (int i = 1; i <= relation[0].size(); i++) {
        choose(0, i, relation);
    }
    return history.size();
}

void choose(int c, int t, vector<vector<string>> &r) {
    for (int i = c; i < r[0].size(); i++) {
        index.push_back((char)(i + 48));

        if (index.size() == t) {
            if (check(index))isKey(r);
            index.pop_back();
        }
        else {
            choose(i + 1, t, r);
            index.pop_back();
        }
    }
}

void isKey(vector<vector<string>>& r) {

    set<string> s;

    for (int i = 0; i < r.size(); i++) {
        string str = "";
        for (int j = 0; j < index.size(); j++) {
            str += r[i][(int)(index[j] - '0')];
        }
        s.insert(str);
    }
    if (s.size() == r.size()) {
        history.push_back(index);
    }
}
bool check(string s) {
    for (int i = 0; i < history.size(); i++) {
        int num = 0;
        for (int j = 0; j < s.size(); j++) {
            if (history[i].find(s[j]) != string::npos)num++;
        }
        if (num == history[i].size())return false;
    }
    return true;
}
