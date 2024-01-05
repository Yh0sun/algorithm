#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int parent[101];

void set_parent(int n) {
    for (int i = 1; i < n + 1; i++)
        parent[i] = i;
}
int find(int x) {
    if (parent[x] == x)
        return x;    
    return parent[x] = find(parent[x]);
}
void tree_union(int x, int y) {
    x = find(x);
    y = find(y);

    if (x > y) parent[x] = y;
    else parent[y] = x;
}
int between_numOfTower(int n) {
    int cnt = 1;
    int num = find(1);
    
    for (int i = 2; i < n + 1; i++) {
        if (find(i) == num)cnt++;
    }
    
    return abs((n - cnt) - cnt);   
}
int solution(int n, vector<vector<int>> wires) {
    int answer = n;

    for (int i = 0; i < n - 1; i++) {
        set_parent(n);
        for (int j = 0; j < n - 1; j++) {
            if (i != j) 
                 tree_union(wires[j][0], wires[j][1]);
        }
        int bnt = between_numOfTower(n);
        if (answer > bnt)answer = bnt;
    }

    return answer;
}
