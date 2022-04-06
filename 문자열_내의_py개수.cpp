#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int num_p = 0;
    int num_y = 0;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;
   
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'p' || s[i] == 'P') num_p++;
        if (s[i] == 'y' || s[i] == 'Y')num_y++;
    }
    if (num_p != num_y)answer = false;
    return answer;
}
