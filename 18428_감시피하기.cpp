#include <iostream>&
#include <vector>
using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int N;
char path[6][6];
vector<pair<int, int>>teacher;

int make_obstacle(int x, int y, int ob_num);
bool judge();

int main(){

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> path[i][j];
			if (path[i][j] == 'T')teacher.push_back({ i,j });
		}
	}
	
	if (!make_obstacle(0, 0, 0))printf("NO\n");
	return 0;
}
int make_obstacle(int x, int y, int ob_num) {

	if (ob_num == 3) {
		if (judge()) {
			printf("YES\n");
			return 1;
		}
		return 0;
	}

	for (int i = x; i < N; i++) {
		int j = 0;
		if (i == x)j = y;
		for (; j < N; j++) {
			if (path[i][j] == 'X') {
				path[i][j] = 'O';
				if (make_obstacle(i, j + 1, ob_num+1))return 1;
				path[i][j] = 'X';
			}
		}
	}
	return 0;
}
bool judge() {

	for (int i = 0; i < teacher.size(); i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 1; k < N; k++) {
				int nx = teacher[i].first + dx[j] * k;
				int ny = teacher[i].second + dy[j] * k;
				if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
					if (path[nx][ny] == 'S')return false;
					else if (path[nx][ny] == 'O') break;
				}
				else break;
			}
		}
	}
	return true;
}
