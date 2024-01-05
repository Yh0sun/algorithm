#include <vector>
#include <cmath>

using namespace std;
bool isPrime(unsigned long long p) {
    if (p < 2)return false;
    if (p == 2 || p == 3)return true;
    for (int i = 2; i <= sqrt(p); i++) {
        if (p % i == 0)return false;
    }
    return true;
}
int solution(int n, int k) {

    int answer = 0;
    vector<int> num;

    while (n > 0) {
        num.push_back(n % k);
        n = n / k;
    }
 
    unsigned long long p = 0;
    for (int i = num.size() - 1; i >= -1; i--) {
        if (i == -1 || num[i] == 0) {
            p /= 10;
            if (isPrime(p))answer++;
            p = 0;
            continue;
        }
        p += num[i];
        p *= 10;
    }
    return answer;
}
