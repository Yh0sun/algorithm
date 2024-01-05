#include <iostream>
#include <string>

using namespace std;

class turtle {
public: 
	int x = 0;
	int y = 0;
	int dir = 1;
	int maxX = 0;
	int maxY = 0;
	int minX = 0;
	int minY = 0;
public:
	void move_front() {
		if (dir == 1)y++;
		else if (dir == 2)x++;
		else if (dir == 3)y--;
		else x--;
	}
	void move_back() {
		if (dir == 1)y--;
		else if (dir == 2)x--;
		else if (dir == 3)y++;
		else x++;
	}
	void rotateL() {
		dir--;
		if (dir <1)dir = dir + 4;
	}
	void rotateR() {
		dir++;
		if (dir > 4)dir = dir % 4;
	}
	void maxminCheck() {
		if (x > maxX)maxX = x;
		if (y > maxY)maxY = y;
		if (x < minX)minX = x;
		if (y < minY)minY = y;
	}
	int makeRectangle() {
		return (maxX - minX) * (maxY - minY);
	}
	void reset() {
		x = 0;
		y = 0;
		dir = 1;	
		maxX = 0;		 
		maxY = 0;		
		minX = 0;
		minY = 0;
	}
};

int main() {
	int t;
	string cmd;
	turtle gobok;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> cmd;
		for (int j = 0; j < cmd.size(); j++) {
			if (cmd[j] == 'F') {
				gobok.move_front();
				gobok.maxminCheck();
			}
			if (cmd[j] == 'B') {
				gobok.move_back();
				gobok.maxminCheck();
			}
			if (cmd[j] == 'L') {
				gobok.rotateL();
				gobok.maxminCheck();
			}
			if (cmd[j] == 'R') {
				gobok.rotateR();
				gobok.maxminCheck();
			}
		}
		cout << gobok.makeRectangle() << endl;
		gobok.reset();
	}
	return 0;
}