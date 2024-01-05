#include <vector>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    vector<int> v(200001);
    for (int i = 0; i < nums.size(); i++) {
        v[nums[i]] = 1;
    }
    for (int j = 0; j < 200001; j++) {
        if (v[j] == 1)answer++;
    }
    if (answer > nums.size() / 2)answer = nums.size() / 2;
    return answer;
}