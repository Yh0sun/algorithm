#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    string stated_a, stated_b;
    unordered_map<string, int> ids;
    vector<pair<int, int>> v;

    for (int i = 0; i < id_list.size(); i++) ids.insert(make_pair(id_list[i], i));

    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());

    for (int i = 0; i < report.size(); i++) {
        int blank = report[i].find(" ");
        stated_a = report[i].substr(0, blank);
        stated_b = report[i].substr(blank + 1);
        v.push_back(make_pair(ids[stated_a], ids[stated_b]));
    }

    int numA[1000] = { 0, };
    int numB[1000] = { 0, };

    for (int i = 0; i < v.size(); i++) numB[v[i].second]++;

    for (int i = 0; i < v.size(); i++)
        if (numB[v[i].second] >= k) numA[v[i].first]++;

    for (int i = 0; i < id_list.size(); i++) answer.push_back(numA[i]);

    return answer;
}
