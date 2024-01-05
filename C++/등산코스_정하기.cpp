#include <string>
#include <vector>
#include <queue>

#define Max 10000000

using namespace std;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
   vector<int> answer = { 0,10000001 };
    vector<vector<pair<int, int>>> Paths(n + 1, vector<pair<int, int>>());
    int check[50001] = { 0, };
    
    for (int i = 0; i < paths.size(); i++) {
        Paths[paths[i][0]].push_back({ paths[i][2],paths[i][1] });
        Paths[paths[i][1]].push_back({ paths[i][2],paths[i][0] });
    }
    
    int num;
    if (gates.size() > summits.size())num = gates.size();
    else num = summits.size();

    for (int i = 0; i < num; i++) {
        if (gates.size() > i)check[gates[i]] = 1;
        if (summits.size() > i)check[summits[i]] = 2;
    }

    for (int i = 0; i < gates.size(); i++) {
        priority_queue<pair<int, int>> pq;
        vector<int> its_table(n + 1, Max);
        int intensity = 0;

        pq.push({ 0,gates[i] });
        check[gates[i]] = 0;
        
        while (!pq.empty()) {  
            int sm = pq.top().second;
            int its = -pq.top().first;
            pq.pop();
          
            if (its_table[sm] != Max) continue;
            
            if (intensity < its)intensity = its;
            its_table[sm] = intensity;
            
            if (check[sm] == 2){
                if (its_table[sm] < answer[1]){
                    answer[0] =  sm;
                    answer[1] = its_table[sm];
                }
                else if (its_table[sm] == answer[1]&&answer[0]>sm)
                    answer[0]=sm;
                if(answer[1]<intensity)break;
                else continue;
            }
            
            if (check[gates[i]] == 0)check[gates[i]] = 1;
            for (int k = 0; k < Paths[sm].size(); k++){ 
                if (check[Paths[sm][k].second] != 1&&its_table[Paths[sm][k].second]==Max)pq.push({ -Paths[sm][k].first,Paths[sm][k].second });
            } 
        }
    }

    return answer;
}