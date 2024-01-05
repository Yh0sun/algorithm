#include <cmath>
using namespace std;

int solution(int left, int right) {
    int answer = 0;

   for (int i = left; i <= right; i++) {
        double tmp = sqrt(i);

        if (tmp-(int)tmp==0.0)answer -= i;
        else answer += i;
    }
    return answer;
}
