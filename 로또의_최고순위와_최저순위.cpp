#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int cnt=0;
    int zeroCnt=0;
    int list[7]={6,6,5,4,3,2,1};
    
    for(int i=0; i<lottos.size();i++){
        if(lottos[i]==0)zeroCnt++;
       
        for(int j=0;j<win_nums.size();j++)
            if(lottos[i]==win_nums[j])cnt++;
    }
    answer.push_back(list[zeroCnt+cnt]);
    answer.push_back(list[cnt]);
    return answer;
}