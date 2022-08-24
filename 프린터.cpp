#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    queue<int> prts;
    queue<int> seq;
   
    for (int i = 0; i < priorities.size(); i++) {
        prts.push(priorities[i]);
        seq.push(i);
    }

    sort(priorities.begin(), priorities.end());
    
    for (;; answer++) {
        while (priorities.back() != prts.front()) {
            prts.push(prts.front());
            prts.pop();
            seq.push(seq.front());
            seq.pop();
        }
        
        if (seq.front() == location)break;
        priorities.pop_back();
        prts.pop();
        seq.pop();
    }

    return answer;
}
