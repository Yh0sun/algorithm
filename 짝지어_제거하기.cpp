#include <iostream>
#include<string>
using namespace std;

int solution(string s)
{
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    string back_s = "";

    while (!s.empty()) {
        back_s.push_back(s.back());
        s.pop_back();

        while (s.back() == back_s.back()) {
            s.pop_back();
            back_s.pop_back();
            if (s.empty() || back_s.empty())break;
        }

    }
    if (back_s.empty())return 1;
    else return 0;
}