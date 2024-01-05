#include <string>
#include <vector>

using namespace std;

int jump(int n, vector<int>& vec) {
    if (n > 2) return vec[n] = (jump(n - 1, vec) % 1234567 + vec[n - 2]) % 1234567;
    return vec[n];
}
long long solution(int n) {
    vector<int> vec(n + 1);
    vec[1] = 1;
    vec[2] = 2;

    jump(n, vec);

    return vec[n];
}
