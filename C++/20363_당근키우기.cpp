#include<iostream>
using namespace std;

int main() {
	int inputX, inputY, result;
	cin >> inputX >> inputY;

	if (inputX > inputY) result = inputX + inputY + inputY / 10;
	else result = inputX + inputY + inputX / 10;

	cout << result;
	return 0;
}