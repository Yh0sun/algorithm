#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    string str = "";
    map<int, int> table;

    for (int i = 2; i < s.size() - 1; i++) {
        if (s[i] == '{' || s[i] == '}' || s[i] == ',') {
            if (str == "")continue;
            if (table.find(stoi(str)) == table.end())table.insert({ stoi(str), 0 });
            table[stoi(str)]++;
            str = "";
            continue;
        }
        str.push_back(s[i]);
    }
    
    vector<pair<int, int>> map(table.begin(), table.end());
    sort(map.begin(), map.end(), comp);
    for (auto i:map) {
        answer.push_back(i.first);
    }
    return answer;
}
