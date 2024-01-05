#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<vector <string>> rcd(record.size(), vector <string>(3));
    map <string, string> table;

    for (int i = 0; i < record.size(); i++) {
        string str = record[i];
        for (int j = 0; j < 3; j++) {
            rcd[i][j] = str.substr(0, str.find(' '));
            str = str.substr(str.find(' ') + 1);
        }
        if (rcd[i][0]=="Change"|| rcd[i][0] == "Enter") table.erase(rcd[i][1]);
        table.insert(make_pair(rcd[i][1], rcd[i][2]));
    }

    for (int i = 0; i < rcd.size(); i++) {
        string str = "";
        if (rcd[i][0] == "Enter") str = table[rcd[i][1]] + "님이 들어왔습니다.";
        if(rcd[i][0]=="Leave") str= table[rcd[i][1]] + "님이 나갔습니다.";

        if (!str.empty())answer.push_back(str);
    }
    return answer;
}
