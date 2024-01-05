#include <iostream>
#include <vector>
#include <string>
using namespace std;

char opr[3] = { ' ','+','-' };

int isZero(vector<char>& list) {

    int sum = 0;
    int num = 1;
    int tmp = 0;
    string str = "1";
    char last_opr = ' ';

    for (int i = 0; i < list.size() + 1; i++) {
        if (i != list.size() && list[i] == ' ') {
            tmp += num++;
            tmp *= 10;
        }
        else {
            if (last_opr == ' ' || last_opr == '+') {
                sum += tmp;
                sum += num++;
            }
            if (last_opr == '-') {
                sum -= tmp;
                sum -= num++;
            }

            if (i == list.size())continue;
            tmp = 0;
            last_opr = list[i];
        }
        str += list[i];
        str += to_string(num);
    }

    if (sum != 0)return false;
    cout << str << "\n";
    return true;
}


int func(int cnt, int goal, int n,vector<char>& opr_list) {
    if (cnt == goal) {
        isZero(opr_list);
        return 0;
    }

    for (int i = 0; i < 3; i++) {
        opr_list.push_back(opr[i]);
        func(cnt + 1, goal,n, opr_list);
        opr_list.pop_back();
    }
    return 0;
}
int main() {
    int test_case, num;
    cin >> test_case;

    for (int i = 0; i < test_case; i++) {
        cin >> num;
        vector<char> vec;
        func(0, num - 1, num, vec);
        cout << "\n";
    }
    return 0;
}