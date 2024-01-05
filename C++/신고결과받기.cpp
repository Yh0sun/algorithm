#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    string stated_a, stated_b;
    vector<string> idList(id_list);

    multimap<string, string> stated;    //신고받은 사람,신고한 사람
    multimap<string, string>::iterator iter;
    multiset <string> list;

    set<string> re;
    set<string>::iterator it;

    for (int i = 0; i < report.size(); i++) {
        re.insert(report[i]);
    }

    sort(idList.begin(), idList.end());

   int index = 0;
    for (it = re.begin(); it != re.end(); it++) {
        string str = *it;
        if (str.find(idList[index]) == 0 && str.find(" ") == idList[index].length()) {
            stated_a = str.substr(0, idList[index].length());
            stated_b = str.substr(idList[index].length() + 1);
            stated.insert(make_pair(stated_b, stated_a));
        }
        else {
            index++;
            it--;
        }
    }

    for (int j = 0; j < id_list.size(); j++) {
        if (stated.count(id_list[j]) >= k) {
            for (iter = stated.lower_bound(id_list[j]); iter != stated.upper_bound(id_list[j]); iter++) {
                list.insert(iter->second);
            }
        }
    }

    for (int j = 0; j < id_list.size(); j++)
        answer.push_back(list.count(id_list[j]));

    return answer;
}
