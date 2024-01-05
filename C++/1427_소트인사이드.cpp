#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(int a,int b) {

	return a > b;
}

int main() {
	string input;
	vector<int> output;

	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		output.push_back(int(input[i]-'0'));
	}

	sort(output.begin(), output.end(), comp);

	for (int i = 0; i < output.size(); i++) {
		cout << output[i];
	}

	return 0;
}