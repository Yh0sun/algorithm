#include <vector>
#include <iostream>

using namespace std;
bool primeNum(int n);
int solution(vector<int> nums) {
    int answer = 0;
    int sum = 0;

    cout << "Hello Cpp" << endl;

    for (int i = 0; i < nums.size() - 2; i++) {
        for (int j = i + 1; j < nums.size() - 1; j++)
            for (int k = j + 1; k < nums.size(); k++) {
                sum = nums[i] + nums[j] + nums[k];
                if (primeNum(sum)) answer++;
            }
    }

    return answer;
}

bool primeNum(int s) {
    bool re = true;

    for (int i = 2; i < s; i++) {
        if (s % i == 0) {
            re = false;
            break;
        }
    }
    return re;
}