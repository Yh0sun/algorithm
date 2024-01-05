#include <vector>

using namespace std;

int visited[21] = { 0, };
vector<int> answer;

int find_permutation(int n, long long num) {
    int round = 0;
    for (int i = 1; i < n + 1; i++) {
        if (visited[i] == 1)continue;
        if (num == ++round) {
            answer.push_back(i);
            visited[i] = 1;
            return 0;
        }
    }
    return 0;
}

vector<int> solution(int n, long long k) {
    long long fac = 1;
    long long arr_fac[21] = { 0, };
    int num;
    for (int i = 1; i < n; i++) {
        fac *= i;
        arr_fac[i] = fac;
    }
  
    for (int i = n - 1; i > 0; i--) {
        if (k % arr_fac[i]) {
            num = k / arr_fac[i] + 1;
            k %= arr_fac[i];
        }
        else {
            num = k / arr_fac[i];
            k = arr_fac[i];
        }
        find_permutation(n, num);
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0)answer.push_back(i);
    }
    return answer;
}
