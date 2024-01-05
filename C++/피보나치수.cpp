#include <string>
#include <vector>

using namespace std;

int fb[100001] = { 0, };

int fibonacci(int x) {
    if (x < 2) return fb[x] = x;
    else {
        fb[x - 1] = fibonacci(x - 1) % 1234567;
        return (fb[x - 1] + fb[x - 2]) % 1234567;
    }
}
int solution(int n) {
    int answer = fibonacci(n);

    return answer;
}