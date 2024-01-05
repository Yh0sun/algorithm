#include <iostream>
#include <vector>
using namespace std;

struct fireBall {
	int mass;
	int speed;
	int drt;
};

int main() {

	int x[8] = { -1,-1,0,1,1,1,0,-1 };
	int y[8] = { 0,1,1,1,0,-1,-1,-1 };
	
	int N, M, K;
	cin >> N >> M >> K;

	vector<vector<vector<fireBall>>> field(N, vector<vector<fireBall>> (N, vector<fireBall>(0)));

	for (int i = 0; i < M; i++) {
		int _r, _c, _m, _s, _d;
		cin >> _r >> _c >> _m >> _s >> _d;
		field[_r - 1][_c - 1].push_back({ _m,_s,_d });
	}

	while (K--) {

		vector<vector<vector<fireBall>>> next_field(N, vector<vector<fireBall>>(N, vector<fireBall>(0)));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k <field[i][j].size(); k++) {
					int next_x = (i + field[i][j][k].speed * x[field[i][j][k].drt]) % N;
					int next_y = (j + field[i][j][k].speed * y[field[i][j][k].drt]) % N;

					if (next_x < 0)next_x = N + next_x;
					if (next_y < 0)next_y = N + next_y;

					next_field[next_x][next_y].push_back(field[i][j][k]);
				}
			}
		}

		field = next_field;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (field[i][j].size() > 1) {
					int num = field[i][j].size();
					int m_total = 0, s_total = 0;
					int odd_even = field[i][j][0].drt % 2;
					bool odd_even_check = true;

					for (int k = num - 1; k >= 0; k--) {
						m_total += field[i][j][k].mass;
						s_total += field[i][j][k].speed;
						if (field[i][j][k].drt % 2 != odd_even)odd_even_check = false;
						field[i][j].pop_back();
					}
					m_total = m_total / 5;
					s_total = s_total / num;
					int plus;
					if (odd_even_check) plus = 0;
					else plus = 1;

					if (m_total > 0) {
						for (int k = 0; k < 4; k++, plus += 2) {
							field[i][j].push_back({ m_total,s_total,plus });
						}
					}
				}
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			for (int k = 0; k < field[i][j].size(); k++) 
				sum += field[i][j][k].mass;

	cout << sum;
	return 0;
}
