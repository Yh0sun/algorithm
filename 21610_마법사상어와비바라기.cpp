#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sky[51][51];
struct cdn {
	int x = 0;
	int y = 0;
};
void waterCopyMagic(vector<cdn>& bm, int n) {
	int x[4] = {-1,-1,1,1};
	int y[4] = {-1,1,1,-1};
	
	for (int i = 0; i < bm.size(); i++) {
		int cnt = 0;
		for (int j = 0; j < 4; j++) {
			int dgn_x = bm[i].x + x[j];
			int dgn_y = bm[i].y + y[j];
			if (0 <= dgn_x && dgn_x < n && 0 <= dgn_y && dgn_y < n) {
				if (sky[dgn_x][dgn_y] > 0)cnt++;
			}
		}
		sky[bm[i].x][bm[i].y] += cnt;
	}
}
void makeCloud(vector<cdn>& cld, vector<cdn>& bm, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (sky[i][j] > 1) {
				bool check = true;
				for (int k = 0; k < bm.size(); k++) {
					if (i == bm[k].x && j == bm[k].y) {
						check = false;
						break;
					}
				}
				if (check) {
					cld.push_back({ i,j });
					sky[i][j] -= 2;
				}
			}
		}
	}
}
int main() {

	int n, m;


	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> sky[i][j];
		}
	}

	vector<cdn> cloud = { {n - 1,0},{n - 1,1},{n - 2,0},{n - 2,1}};
	vector<cdn> beforeMagic;
	int dirX[8] = { 0,-1,-1,-1,0,1,1,1 };
	int dirY[8] = { -1,-1,0,1,1,1,0,-1 };
	for (int i = 0; i < m; i++) {
		int d = 0;
		int s = 0;
		cin >> d >> s;
		for (int j = 0; j < cloud.size(); j++) {
			int next_x = (cloud[j].x + dirX[d - 1] * s) % n;
			int next_y = (cloud[j].y + dirY[d - 1] * s) % n;
			sky[next_x][next_y] += 1;
			beforeMagic.push_back({ next_x,next_y });
		}
		cloud.clear();
		waterCopyMagic(beforeMagic, n);
		makeCloud(cloud, beforeMagic, n);
	}

	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum += sky[i][j];
		}
	}

	cout << sum;
	return 0;
}
