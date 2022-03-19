#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string str = to_string(n);

    for (int i = str.size(); i > 0; --i) {
        answer.push_back(str[i - 1]-'0');
    }
    return answer;
}
