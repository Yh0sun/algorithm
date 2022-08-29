#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool comp(string a, string b) {
    if (a.size() == b.size()) return a > b;
    else if (a > b) {
        if (a + b > b + a) return a > b;
        else return a < b;
    }
    else {
        if (a + b > b + a) return a < b;
        else return a > b;
    }
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> num_str;
   
     for (int i = 0; i < numbers.size(); i++)
        num_str.push_back(to_string(numbers[i]));

    sort(num_str.begin(), num_str.end(), comp);

    for (int i = 0; i < num_str.size(); i++)
        answer += num_str[i];
      
    if (answer[0]=='0')return "0";
    return answer;
}
