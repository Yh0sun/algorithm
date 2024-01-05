#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<vector <int>> friends;
int seat[20][20] = { 0, };

void friendsCount(int p);
long calSatisfy();

int main() {
	
	friends.resize(500);
	cin >> N;

	for (int i = 0; i < N*N; i++) {
		int person;
		cin >> person;
		for (int j = 0; j < 4; j++) {
			int tmp;
			cin >> tmp;
			friends[person].push_back(tmp);
		}

		if (i == 0) {
			seat[1][1] = person;
		}
		else {
			friendsCount(person);
		}
	}

	cout << calSatisfy();
	return 0;
}

void friendsCount(int person) {
	vector<vector <pair<int, int>>> cnt;
	int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
	int maxfriendsCnt = 0;

	for (int i = 0; i < N; i++) {
		vector <pair<int, int>> v;
		for (int j = 0; j < N; j++) {
			int zeroCnt = 0, friendsCnt = 0;
			if (seat[i][j] == 0) {
				for (int k = 0; k < 4; k++) {
					int Xaround = i + dir[k][0];
					int Yaround = j + dir[k][1];
					if (Xaround >= 0 && Xaround < N && Yaround >= 0 && Yaround < N) {
						if (seat[Xaround][Yaround] == 0) {
							zeroCnt++;
						}
						else {
							if (find(friends[person].begin(), friends[person].end(), seat[Xaround][Yaround]) != friends[person].end()) {
								friendsCnt++;
							}
						}
					}
				}
			}

			if (maxfriendsCnt < friendsCnt)maxfriendsCnt = friendsCnt;
			v.push_back(make_pair(zeroCnt, friendsCnt));
		}
		cnt.push_back(v);
	}

	int maxZero = -1;
	int x, y;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (seat[i][j] == 0) {
				if (cnt[i][j].second == maxfriendsCnt) {
					if (cnt[i][j].first > maxZero) {
						maxZero = cnt[i][j].first;
						x = i;
						y = j;
					}
				}
			}
		}
	}
	seat[x][y] = person;
}

long calSatisfy() {

	int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
	long satisfyRate = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int friendsCnt = 0;
			int middlePer = seat[i][j];
			for (int k = 0; k < 4; k++) {
				int Xaround = i + dir[k][0];
				int Yaround = j + dir[k][1];
				if (Xaround >= 0 && Xaround < N && Yaround >= 0 && Yaround < N) {
					if (find(friends[middlePer].begin(), friends[middlePer].end(), seat[Xaround][Yaround]) != friends[middlePer].end()) {
						friendsCnt++;
					}
				}
			}
			if (friendsCnt == 0)satisfyRate += (long)friendsCnt;
			else satisfyRate += (long)pow(10, (friendsCnt - 1));
		}
	}
	return satisfyRate;
}
