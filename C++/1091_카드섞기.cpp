#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
vector<int> result;
vector<int> seq;

bool isRight();

int main() {

	vector<int> shuffle;
	vector<int> tmp;
	int cnt = 0;
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		result.push_back(num);
		seq.push_back(i);
	}
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		shuffle.push_back(num);
		tmp.push_back(0);
	}
	
	while (true) {

		if (isRight()) break;

		if (cnt > 1000000) {
			cnt = -1;
			break;
		}

		cnt++;
		for (int i = 0; i < n; i++) {
			tmp[shuffle[i]] = seq[i];
		}
		seq.clear();
		seq = tmp;   //tmp를 seq로 넣기
	}

	cout << cnt;

	return 0;
}

bool isRight() {
	bool re = true;
	for (int i = 0; i < n; i++) {
		if (result[seq[i]] == i % 3) continue;
		else {
			re = false;
			break;
		}
	}
	return re;
}