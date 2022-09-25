#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
map<string, vector<int>> m;

bool comp(string a, string b) {
    int i = a.size() - 1, j = b.size() - 1;
    for (; i >= 0; i--) {
        if (a[i] == ' ') {
            break;
        }
    }
    for (; j >= 0; j--) {
        if (b[j] == ' ') {
            break;
        }
    }
    return stoi(a.substr(i + 1)) > stoi(b.substr(j + 1));
}

int func(vector<string>& str,int& idx, string map_string,int num,int cnt,int& target) {
    if (cnt == target) {
        m[map_string].push_back(idx);
        return 1;
    }
    for (int i = num; i < str.size(); i++) 
        func(str, idx, map_string + str[i], i + 1, cnt + 1, target);
    return 1;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    map<int, int> score;

    sort(info.begin(), info.end(), comp);

    for (int i = 0; i < info.size(); i++) {
        vector<string> str;
        int start = 0;
        for (int j = 0; j < info[i].size(); j++) {
            if (info[i][j] == ' ') {
                str.push_back(info[i].substr(start, j - start));
                start = j + 1;
            }
        }
        score[i] = stoi(info[i].substr(start));
        for (int j = 1; j < 5; j++) 
            func(str, i, "", 0, 0, j);
    }
    
    for (int i = 0; i < query.size(); i++) {
        string words = "";
        int start = 0;
        for (int j = 0; j < query[i].size(); j++) {
            if (query[i][j] == ' ') {
                string word = query[i].substr(start, j - start);
                if (word != "-" && word != "and")words += word;
                start = j + 1;
            }
        }
        
        int val = stoi(query[i].substr(start));
       
        if (words.empty()) {
            int t1 = 0;
            int t2 = info.size() - 1;
            int mid = 0;
         
            while (t1<=t2) {
                    mid = (t2 + t1) / 2;
                    if (score[mid] >= val)t1 = mid+1;
                    else t2 = mid-1;
            }
            answer.push_back(t1);
          
        }
        else {
            int t1 = 0;
            int t2 = m[words].size() - 1;
            int mid = 0;
            while (t1<=t2) {
                    mid = (t2 + t1) / 2;
                    if (score[m[words][mid]] >= val)t1 = mid+1;
                    else t2 = mid-1;
            }
            answer.push_back(t1);
        }
    }
    return answer;
}
