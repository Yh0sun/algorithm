#include <iostream>

using namespace std;

int main() {

	string str_s, str_p;
	cin >> str_s >> str_p;

	if (str_s.find(str_p) != string::npos)printf("1");
	else printf("0");

	return 0;
}
