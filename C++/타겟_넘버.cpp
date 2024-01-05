#include <vector>
using namespace std;

vector<int> num;
int t;
int answer = 0;
void cal(int i, int s);

int solution(vector<int> numbers, int target) {
    num.swap(numbers);
    t = target;

    cal(0, 0);

    return answer;
}
void cal(int i, int s) {

    if (i == num.size()) {
        if (s == t)answer++;
    }
    else {
        int nextMimus = s - num[i];
        cal(i + 1, nextMimus);

        int nextPlus = s + num[i];
        cal(i + 1, nextPlus);
    }
}
