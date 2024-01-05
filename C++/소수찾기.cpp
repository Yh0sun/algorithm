#include <string>
#include <vector>
#include <cmath>
using namespace std;

string num = "";
int visited[7] = { 0, };
int numVisited[10000000] = { 0, };

bool isPrime(string num) {
    int n = stoi(num);
    if (numVisited[n] == 1)return false;
    numVisited[n] = 1;
    if (n < 2)return false;
    for (int i = 2; i <= sqrt(n); i++) 
        if (n % i == 0)return false;
    return true;
}
int permutation(int numSize, string& numbers, int& ans) {
    if (num.size() == numSize) {
        if (isPrime(num)) ans++;
        return 0;
    }
    for (int i = 0; i < numbers.size(); i++) {
        if (visited[i] == 1)continue;
        if (num.size() == 0 && numbers[i] == '0')continue;

        num += numbers[i];
        visited[i] = 1;
        permutation(numSize, numbers, ans);
        num.pop_back();
        visited[i] = 0;
    }
    return 0;
}

int solution(string numbers) {
    int answer = 0;

    for (int i = 1; i <= numbers.size(); i++)
        permutation(i, numbers, answer);

    return answer;
}