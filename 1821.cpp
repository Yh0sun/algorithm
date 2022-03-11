#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, final;
//int cnt = 0;
vector<int> seq;
bool sucess = false;
void makeSeq();
int makefinal(); 
int main() {


	cin >> N >> final;
	
	makeSeq();

	for (int i = 0; i < N; i++) {
		cout << seq[i] << " ";
	}
	return 0;
}
void makeSeq() {

	for (int i = 1; i <= N; i++) {
		if (find(seq.begin(), seq.end(), i) == seq.end()) {
			seq.push_back(i);
			if (seq.size() != N) {
				makeSeq();
				seq.pop_back();
			}
			else {
				if (makefinal() == final)sucess = true;
				else seq.pop_back();
			}
			if (sucess)break;
		}
	
	}
}
int makefinal() {
	int f;
	f = seq[0] + seq[N - 1];

	for (int i = 1; i < N - 1; i++) {
		f += seq[i] * (N - 1) * i;
	}
	return f;
}
