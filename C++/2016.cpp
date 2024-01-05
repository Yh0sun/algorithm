#include <string>

using namespace std;

string solution(int a, int b) {
    string answer[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
    int month[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
    int num = b + 4;

    for (int i = 0; i < a-1; i++) {
        num += month[i];
    }

    return  answer[num % 7];
}
