#include <vector>
#include<algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    int arr[31] = { 0, };
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    for (int i = 0; i < reserve.size(); i++) {
        arr[reserve[i]] = 1;
    }

    for (int i = 0; i < lost.size(); i++) {
        if (arr[lost[i]] == 1) {
            arr[lost[i]] = 0;
            lost.erase(lost.begin() + i);
            lost.insert(lost.begin() + i, 0);
        }
    }
 
    for (int i = 0; i < lost.size(); i++) {
        if (lost[i] == 0) continue;
        else if (arr[lost[i] - 1] == 1)
            arr[lost[i] - 1] = 0;
        else if (arr[lost[i] + 1] == 1)
            arr[lost[i] + 1] = 0;
        else --answer;
    }

    return answer;
}