#include<iostream>
#include<queue>
using namespace std;
int arr[301][301]; 
int n, m, r;
void rotate(int a);

int main() {	
	int smallnum;
	cin >> n >> m >> r;
	
	if (n > m)smallnum = m;
	else smallnum = n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	for (int i = 0; i < smallnum / 2; i++)
		rotate(i);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

void rotate(int a) {

	queue<int> line;

	for (int i = a; i < m - a - 1; i++)
		line.push(arr[a][i]);
	for (int i = a; i < n - a - 1; i++)
		line.push(arr[i][m - a - 1]);
	for (int i = m - a - 1; i > a; i--)
		line.push(arr[n - a - 1][i]);
	for (int i = n - a - 1; i > a; i--)
		line.push(arr[i][a]);

	for (int j = 0; j < r; j++) {
		line.push(line.front());
		line.pop();
	}

	for (int i = a; i < m - a - 1; i++) {
		arr[a][i] = line.front();
		line.pop();
	}
	for (int i = a; i < n - a - 1; i++) {
		arr[i][m - a - 1] = line.front();
		line.pop();
	}
	for (int i = m - a - 1; i > a; i--) {
		arr[n - a - 1][i] = line.front();
		line.pop();
	}
	for (int i = n - a - 1; i > a; i--) {
		arr[i][a] = line.front();
		line.pop();
	}
}