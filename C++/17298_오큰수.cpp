#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> input(n);
	vector<int> ans(n);
	stack<int> tmp;

	for (int i = 0; i < n; i++)
		cin >> input[i];

	ans[n - 1] = -1;
	tmp.push(input[n - 1]);

	for (int i = n - 2; i > -1; i--) {
		while (tmp.top() <= input[i]) {
			tmp.pop();
			if (tmp.empty()) {
				ans[i] = -1;
				break;
			}	
		}
		if (!tmp.empty() && tmp.top() > input[i]) ans[i] = tmp.top();
		tmp.push(input[i]);
	}

	for (int i = 0; i < n; i++) 
		cout << ans[i] << " ";

	return 0;
}
