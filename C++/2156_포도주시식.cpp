#include<iostream>
using namespace std;
int maxNum(int a, int b, int c);

int main() {
    int num;
    int glass[10001] = { 0, };
    int dp[4][10001] = { 0, };

    cin >> num;
    for (int j = 1; j <= num; j++) {
        cin >> glass[j];
    }

    for (int i = 1; i <= num; i++) {
        if (i <= 2) {
            dp[1][i] = glass[i] + glass[i - 1];
            dp[2][i] = glass[i] + glass[i - 1];
            dp[3][i] = glass[i] + glass[i - 1];
        }
        else {
            dp[1][i] = dp[0][i - 3] + glass[i];
            dp[2][i] = dp[0][i - 3] + glass[i - 1] + glass[i];
            dp[3][i] = dp[0][i - 2] + glass[i];
        }
        dp[0][i] = maxNum(dp[1][i], dp[2][i], dp[3][i]);
        if (dp[0][i] < dp[0][i - 1])dp[0][i] = dp[0][i - 1];
    }
    cout << dp[0][num];
    return 0;
}

int maxNum(int a, int b, int c) {
    int max = -1;

    if (a > max)max = a;
    if (b > max)max = b;
    if (c > max)max = c;
    return max;
}