#include <string>
#include <algorithm>
using namespace std;

int solution(string s) {
    int answer = 1000;

    for (int i = 1; i <= s.size(); i++) {
        string tmp = s;
        string str = tmp.substr(0, i);
        string result = "";
        int cnt = 0;

        while (true) {
            if (tmp.size() < i) {
                if (cnt != 1)result += to_string(cnt);
                result += str;
                result += tmp;
                break;
            }

            if (str == tmp.substr(0, i)) {
                cnt++;  
                tmp = tmp.substr(i); 
            }
            else {
                if (cnt != 1)result += to_string(cnt);
                result += str;
                cnt = 0;
                str = tmp.substr(0, i);
            }
        }

        int size = result.size();
        answer = min(answer, size);
    }
    return answer;
}
