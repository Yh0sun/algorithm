#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    set<string> s;
    s.insert(words[0]);
    
    for (int i = 1; i < words.size(); i++) {
        s.insert(words[i]);
        if (s.size() != i + 1 || words[i][0] != words[i - 1].back()) {
            return {i%n+1,i/n+1};
        }
    }
    return {0,0};
}
