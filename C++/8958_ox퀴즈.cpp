#include<iostream>
using namespace std;

int main() {
	int case_num, score = 0, total = 0;
	string ox;

	cin >> case_num;

	for (int n = 0; n < case_num; n++) {
		cin >> ox;
		for (int i = 0;i<ox.length(); i++) {
			for (int j = 0; j <= i; j++) {
				if (ox[j] == 'O')score++;
				else score = 0;				
			}
			total += score;
			score = 0;
		}
		cout << total << endl;
		total = 0;
	}

	return 0;
}