#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer(arr);
   
    answer.erase(min_element(answer.begin(), answer.end()));
    if (answer.empty())answer.push_back(-1);

    return answer;
}
