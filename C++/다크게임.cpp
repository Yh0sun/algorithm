#include <string>
#include <cmath>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int arr[10] = { 0, };

    for (int i = 0; i < dartResult.size(); i++) {
        if (dartResult[i]>'9') {
            int multi = 0;

            if (dartResult[i] == 'S')multi = 1;
            if (dartResult[i] == 'D')multi = 2;
            if (dartResult[i] == 'T')multi = 3;

            if (dartResult[i - 1] == '0' && dartResult[i - 2] == '1') {
                arr[i] = pow(10, multi);
            }
            else {
                arr[i] = pow((dartResult[i - 1] - '0'), multi);
            }
        }
    }

    for (int i = 0; i < dartResult.size(); i++) {
        if (dartResult[i] == '*') {
            arr[i - 1] *= 2;
            arr[i - 3] *= 2;
            arr[i - 4] *= 2;
        }
        if (dartResult[i] == '#') {
            arr[i - 1] *= (-1);
        }
    }

    for (int i = 0; i < 10; i++) {
        answer += arr[i];
    }

    return answer;
}
