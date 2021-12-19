#include <iostream>
#include <vector>
using namespace std;
void progression(int c);
vector<int> out;
int done[9];
int n, m;

int main() {
	vector<int> input;
	int count = 0;
	
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		input.push_back(i);
	}
	progression(count);
	return 0;
}

void progression(int count) {
	if (count == m) {
		for (int j = 0; j < out.size(); j++) {
			cout << out[j] << " ";
		}
		cout << "\n";
	}
	else
		for (int i = 1; i <= n; i++) {
			if (done[i] == 0) {
				count++;
				out.push_back(i);
				done[i] = 1;
				progression(count);
				done[out.back()] = 0;
				out.pop_back();
				count--;
			}
		}
}