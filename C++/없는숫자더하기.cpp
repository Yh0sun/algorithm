#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    bool ox[10]={false};
    for(int i=0;i<numbers.size();i++)
        ox[numbers[i]]=true;
    for (int i = 0; i < 10; i++) {
        if (ox[i] == false)answer += i;
    }
    return answer;
}