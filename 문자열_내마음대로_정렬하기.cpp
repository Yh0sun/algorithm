#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> strings, int n) {

    vector<string> answer;
    multimap<char, string> st;
    string each;

    multimap<char, string>::iterator it;

    sort(strings.begin(), strings.end());

    for (int i = 0; i < strings.size(); i++) {
        each = strings[i];
        st.insert(make_pair(each[n], strings[i]));
    }

    for (it = st.begin(); it != st.end(); it++) {
        answer.push_back(it->second);
    }

    return answer;
}