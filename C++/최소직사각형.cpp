#include <vector>
#include<algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int maxH = 0, maxW = 0;

    for (int i = 0; i < sizes.size(); i++) {
        sort(sizes[i].begin(), sizes[i].end());
    }

    for (int i = 0; i < sizes.size(); i++) {
        if (sizes[i][0] > maxW)maxW = sizes[i][0];
        if (sizes[i][1] > maxH)maxH = sizes[i][1];
    }
    
    return maxH * maxW;
}