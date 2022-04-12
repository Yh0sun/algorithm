#include <vector>
using namespace std;

int answer = 0;

/* & 참조자 - 별명을 붙여준다.
  vector<int> &num=numers
  num을 호출하면 numbers 값 호출
*/

void cal(vector<int> &num, int i, int sum, int &t) {
    if (i == num.size()) {
        if (sum == t)answer++;
    }
    else {
        cal(num, i + 1, sum - num[i], t);
        cal(num, i + 1, sum + num[i], t);
    }
}
int solution(vector<int> numbers, int target) {
    
    cal(numbers, 0, 0, target);
    return answer;
}
