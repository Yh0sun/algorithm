#include <string>
#include <vector>
#include <set>
using namespace std;

struct ability
{
    int Alp;
    int Cop;
    int Re;
    
    bool operator<(const ability& other) const{
        if (Alp == other.Alp) {
            if (Cop == other.Cop) {
                return Re < other.Re;
            }
            return Cop < other.Cop;
        }
        return Alp < other.Alp;
    }
};

vector<set<ability>> Cost(1001, set<ability>());
int alp_goal = 0, cop_goal = 0;

int sucess_check(int alp, int cop, int re) {
    if (alp < alp_goal) {
        re -= (alp_goal - alp);
    }
    if (cop < cop_goal) {
        re -= (cop_goal - cop);
    }
    if (re >= 0) {
        return 1;
    }
    return 0;
}
int solution(int alp, int cop, vector<vector<int>> problems) {

    for (int i = 0; i < problems.size(); i++) {
        if (alp_goal < problems[i][0])alp_goal = problems[i][0];
        if (cop_goal < problems[i][1])cop_goal = problems[i][1];
    }
   
    Cost[0].insert({ alp,cop,0 });
    
    for (int i = 1; i < 10001; i++) {
        for (int j = 0; j < problems.size(); j++) {
            int alp_req = problems[j][0];
            int cop_req = problems[j][1];
            int alp_rwd = problems[j][2];
            int cop_rwd = problems[j][3];
            int cost = problems[j][4];

            if (i >= cost) {
                for (auto& k: Cost[i - cost]) {
                    int _alp = k.Alp;
                    int _cop = k.Cop;
                    int remain = k.Re;
                   
                    if (_alp < alp_req) {
                        remain -= (alp_req - _alp);
                        _alp = alp_req;
                    }
                    if (_cop < cop_req) {
                        remain -= (cop_req - _cop);
                        _cop = cop_req;
                    }
                   
                    if (remain >= 0) {
                        Cost[i].insert({ _alp + alp_rwd, _cop + cop_rwd,remain });
                        if (sucess_check(_alp + alp_rwd, _cop + cop_rwd, remain)) {                           
                            return i;
                        }
                    }
                }
            }  
        }
        for (auto& k : Cost[i - 1]) {
            Cost[i].insert({ k.Alp,k.Cop, k.Re + 1 });
            if (sucess_check(k.Alp, k.Cop, k.Re + 1)) {                
                return i;
            }
        }
    }
}
