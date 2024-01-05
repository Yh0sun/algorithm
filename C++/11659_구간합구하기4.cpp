#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	vector<int> vec;
	int N, M, a, b, tmp;
	cin >> N >> M;

	vec.push_back(0);
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		vec.push_back(tmp);
		vec[i] += vec[i - 1];
	}
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		cout << vec[b] - vec[a - 1] << "\n";
	}
	return 0;
}
