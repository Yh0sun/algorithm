#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for (int i = 0; i < n; i++) {
        int ans = arr1[i] | arr2[i];
        string str = "";
        for (int j = 0; j < n; j++) {
            if (ans % 2) str = "#" + str;
            else str = " " + str;
            ans /= 2;
        }
        answer.push_back(str);
    }
    return answer;
}
