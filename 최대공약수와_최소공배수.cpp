#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int x, y;

    if (n > m) {
        x = n;
        y = m;
    }
    else {
        x = m;
        y = n;
    }

    while (y!=0) {
        int tmp = y;
        y = x % y;
        x = tmp;
    }

    answer.push_back(x);
    answer.push_back(x * (m / x) * (n / x));
    
    return answer;
}
