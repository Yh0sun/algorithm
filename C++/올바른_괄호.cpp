#include<string>
#include <iostream>
#include <stack>

using namespace std;
bool solution(string s)
{
    bool answer = true;
    stack<int> st;
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(')st.push('(');
        else
        {
            if (st.empty())return false;
            st.pop();
        }
    }
    if (!st.empty())return false;
    return answer;
}