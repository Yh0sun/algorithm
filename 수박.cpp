#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1)answer += "��";
        if (i % 2 == 0)answer += "��";
    }
    return answer;
}