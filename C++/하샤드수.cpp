#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = false;
    int x_copy = x;
    int sum = 0;

    while (x_copy != 0) {
        int num = x_copy % 10;
        x_copy = x_copy / 10;
        sum += num;
    }

    if (x % sum == 0)answer = true;

    return answer;
}
