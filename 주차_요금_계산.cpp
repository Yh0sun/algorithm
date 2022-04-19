#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool compare(string a, string b) {
    int a_num = stoi(a.substr(6, 4));
    int b_num = stoi(b.substr(6, 4));
    
   if (a_num == b_num) {
        return a < b;
    }
    else return a_num < b_num;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map <string, int> table;

    sort(records.begin(), records.end(), compare);
    
     for (int i = 0; i < records.size(); i++) {
        int time = -1;

        string cn = records[i].substr(6, 4);
        int h = stoi(records[i].substr(0, 2));
        int m = stoi(records[i].substr(3, 2));
        string inout = records[i].substr(11);
       
        string n_cn = "";
        int nh = 0;
        int nm = 0;
        string n_inout = "";

        if (i != records.size() - 1) {
            n_cn = records[i + 1].substr(6, 4);
            nh = stoi(records[i + 1].substr(0, 2));
            nm = stoi(records[i + 1].substr(3, 2));
            n_inout = records[i + 1].substr(11);
        }
        
        int start = h * 60 * 60 + m * 60;

        if (inout == "IN") {
          
            if (cn == n_cn) {
                int end = nh * 60 * 60 + nm * 60;
                time = (end - start) / 60;
            }
            else {
                int end = 23 * 60 * 60 + 59 * 60;
                time = (end - start) / 60;
            }

            if (table.find(cn) != table.end()) {
                int tmp = table[cn] + time;
                table.erase(cn);
                table[cn] = tmp;
            }
            else table.insert({cn, time});
        }
    }
    
     for (auto iter : table) {
        if (iter.second <= fees[0])answer.push_back(fees[1]);
        else {
            int f = (iter.second - fees[0]) / fees[2];
            if ((iter.second - fees[0]) % fees[2] != 0)f += 1;
            
            answer.push_back(fees[1] + f * fees[3]);
        }
     }
    
    return answer;
}
