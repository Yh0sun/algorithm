#include<iostream>
using namespace std;
class point {
private:
	int direction = 0;
	int x = 0;
	int y = 0;

public:
	void point_direction(int num)
	{
		if (num == 1) {
			direction--;
			if (direction < 0)direction = 3;
		}
		if (num == 0) {
			direction++;
		}
		direction = direction % 4;
	}

	void point_move(int num)
	{
		if (direction == 0)
			x += num;
		if (direction == 1)
			y += num;
		if (direction == 2)
			x -= num;
		if (direction == 3)
			y -= num;
	}

	bool point_out(int M) {
		if (x > M || y > M || x < 0 || y < 0)
			return true;
		else
			return false;

	}

	void whereisPoint()
	{
		cout << x << " " << y;
	}
};

int main() {
	int M, n, num;
	string commend;
	point now;

	cin >> M >> n;

	for (int i = 0; i < n; i++) {
		cin >> commend >> num;

		if (commend == "MOVE")
			now.point_move(num);
		if (commend == "TURN")
			now.point_direction(num);

		if (now.point_out(M)) {
			cout << "-1";
			break;
		}
	}

	if (!now.point_out(M))
		now.whereisPoint();

	return 0;
}