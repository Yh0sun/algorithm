#include<iostream>
using namespace std;

int main() {
	int num, input;
	int arr[100001] = { 0, };
	int sticker = 0, bigsticker = 0;

	cin >> num;

	do {
		cin >> input;
		arr[input]++;

		if (arr[input] == 1)sticker++;
		if (arr[input] == 2)sticker--;

		if (bigsticker < sticker)bigsticker = sticker;
	} while (getc(stdin) == ' ');

	cout << bigsticker;
	return 0;
}