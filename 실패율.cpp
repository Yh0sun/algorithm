#include <vector>
#include <set>
#include <map>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    multiset <int> sta;
    multimap<double, int, greater<double>> failurelate;
    int peopleInStage = stages.size();
    int failPeople;
    double fl;

    multimap<double, int>::iterator it;

    for (int i = 0; i < stages.size(); i++) 
        sta.insert(stages[i]);
    
    for (int i = 1; i <= N; i++) {

        failPeople = sta.count(i);

        if (peopleInStage == 0) fl = 0;
        else fl = (double)failPeople / peopleInStage;
        
        failurelate.insert(make_pair(fl, i));

        peopleInStage -= failPeople;

    }

    for (it = failurelate.begin(); it != failurelate.end(); it++)
        answer.push_back(it->second);
    
    return answer;
}