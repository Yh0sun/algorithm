#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, final;
vector<int> seq;
bool sucess = false;

void makeSeq();
int makefinal(); 

int main() {

	cin >> N >> final;

	makeSeq();

	for (int k = 0; k < N; k++) {
		cout << seq[k] << " ";
	}

	return 0;
}
void makeSeq() {

	for (int i = 1; i <= N; i++) {
		if (find(seq.begin(), seq.end(), i) == seq.end()) {
			seq.push_back(i);
			if (seq.size() != N) {
				makeSeq();
				if (!sucess)seq.pop_back();
			}
			else {
				if (makefinal() == final) sucess = true;
				else seq.pop_back();
			}
			if (sucess)break;
		}
	}
}
int makefinal() {
	vector<int> v(seq);

	for (int j = 0; j < N - 1; j++) {
		vector<int> v2;
		for (int i = 0; i < v.size() - 1; i++) {
			v2.push_back(v[i] + v[i + 1]);
		}
		v.clear();
		v.swap(v2);
	}
	return v[0];
}
