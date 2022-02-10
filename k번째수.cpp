#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {

    vector<int> answer;
    vector<int> edit;

    for (int i = 0; i < commands.size(); i++) {

        int start = commands[i][0] - 1;
        int end = commands[i][1];
        int qjsWo = commands[i][2] - 1;

        edit.clear();

        for (int j = start; j < end; j++) {
            edit.push_back(array[j]);
        }

        sort(edit.begin(), edit.end());

        answer.push_back(edit[qjsWo]);
    }

    return answer;
}