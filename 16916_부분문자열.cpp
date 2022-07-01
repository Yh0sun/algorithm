#include <iostream>
#include <regex>

using namespace std;

int main() {


	string str_s, str_p;
	cin >> str_s >> str_p;

	regex re(str_p);
	cout<<regex_search(str_s, re);

	return 0;
}
