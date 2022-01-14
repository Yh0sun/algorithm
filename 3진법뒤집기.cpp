#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> remain;

    while (true) {
        if (n < 3) {
            remain.push_back(n);
            break;
        }
        remain.push_back(n % 3);
        n = n / 3;
    }

    int num = remain.size();
    
    for (int i = 0; i < num; i++) {
        answer += remain[i] * pow(3, num - 1 - i);
    }
    
    return answer;
}