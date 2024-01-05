#include <iostream>
#include <algorithm>
#include<cstring>
using namespace std;

int arr[3][1000001] = { 0, };
int mdp[3][1000001] = { 0, };

int main() {

	int testcase, n;

	cin >> testcase;

	for (int i = 0; i < testcase; i++) {

		cin >> n;

		for (int j = 1; j <= 2; j++)
			for (int k = 1; k <= n; k++)
				cin >> arr[j][k];

		for (int k = 1; k <= n; k++)
			for (int j = 1; j <= 2; j++) {
				if (k == 1) {
					mdp[1][k] = arr[1][1];
					mdp[2][k] = arr[2][1];
					mdp[0][k] = max(mdp[1][k], mdp[2][k]);
				}
				else {
					if (j == 1)
						mdp[1][k] = max(mdp[0][k - 1], mdp[2][k - 1] + arr[j][k]);
					else
						mdp[2][k] = max(mdp[0][k - 1], mdp[1][k - 1] + arr[j][k]);

					mdp[0][k] = max(mdp[1][k], mdp[2][k]);
				}
			}

		cout << mdp[0][n] << endl;
		memset(arr, 0, sizeof(arr));
		memset(mdp, 0, sizeof(mdp));
	}

	return 0;
}