#include <vector>

using namespace std;

int solution(int num) {
    long long Num = num;
    int answer;
    
    for (answer = 0; answer <= 500; answer++) {
        if (Num == 1) break;

        if (Num % 2) Num = Num * 3 + 1;
        else Num = Num / 2;
    }

    if (answer == 501) return -1;
    else return answer;
}