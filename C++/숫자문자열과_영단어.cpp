#include <string>
#include <map>
using namespace std;

int solution(string s) {

    map<string, string> table;
    table["zero"] = "0";
    table["one"] = "1";
    table["two"] = "2";
    table["three"] = "3";
    table["four"] = "4";
    table["five"] = "5";
    table["six"] = "6";
    table["seven"] = "7";
    table["eight"] = "8";
    table["nine"] = "9";

    string anw = "";
    string en = "";

    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            anw += s[i];
        }
        else {
            en += s[i];
            if (table.find(en) != table.end()) {
                anw += table.find(en)->second;
                en = "";
            }
        }
    }
    int answer = stoi(anw);
    return answer;
}