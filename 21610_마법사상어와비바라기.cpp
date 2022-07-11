#include <iostream>
#include <vector>

using namespace std;

int n, m;
int sky[51][51];

struct cdn {
	int x = 0;
	int y = 0;
};

void waterCopyMagic(vector<cdn>& n_cld) {
	int x[4] = { -1,-1,1,1 };
	int y[4] = { -1,1,1,-1 };

	for (int i = 0; i < n_cld.size(); i++) {
		int cnt = 0;
		for (int j = 0; j < 4; j++) {
			int dgn_x = n_cld[i].x + x[j];
			int dgn_y = n_cld[i].y + y[j];
			if (0 <= dgn_x && dgn_x < n && 0 <= dgn_y && dgn_y < n) {
				if (sky[dgn_x][dgn_y] > 0)cnt++;
			}
		}
		sky[n_cld[i].x][n_cld[i].y] += cnt;
	}
}
void findNextCloud(vector<cdn>& cld, vector<cdn>& n_cld, int d, int s) {
	int dirX[8] = { 0,-1,-1,-1,0,1,1,1 };
	int dirY[8] = { -1,-1,0,1,1,1,0,-1 };

	for (int j = 0; j < cld.size(); j++) {
		int next_x = (cld[j].x + dirX[d - 1] * s) % n;
		int next_y = (cld[j].y + dirY[d - 1] * s) % n;
		if (next_x < 0)next_x += n;
		if (next_y < 0)next_y += n;

		sky[next_x][next_y] += 1;

		n_cld.push_back({ next_x,next_y });
	}
}
void makeCloud(vector<cdn>& cld, vector<cdn>& n_cld) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (sky[i][j] > 1) {
				bool check = true;
				for (int k = 0; k < n_cld.size(); k++) {
					if (i == n_cld[k].x && j == n_cld[k].y) {
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

	cin >> n >> m;

	vector<cdn> cloud = { {n - 1,0},{n - 1,1},{n - 2,0},{n - 2,1} };
	vector<cdn> nextCloud;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> sky[i][j];
		}
	}
	
	for (int i = 0; i < m; i++) {
		int dir = 0, distance = 0;
		cin >> dir >> distance;
		
		findNextCloud(cloud, nextCloud, dir, distance);
		cloud.clear();
		waterCopyMagic(nextCloud);
		makeCloud(cloud, nextCloud);
		nextCloud.clear();

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
