#include<iostream>
#include<algorithm>
using namespace std;


int main() {
	int num, result[1000], max = 0, maxNum = 0;
	string BookName[1000];

	cin >> num;
	
	for (int x = 0; x < num; x++) {
		result[x] = -1;
	}

	for (int i = 0; i < num; i++) {
		cin >> BookName[i];
	}

	sort(BookName, BookName + num);

	for (int j = 0; j < num; j++) 
		for (int k = 0; k < num; k++) 
			if (BookName[j] == BookName[k]) 
				result[j]++;
	
	for (int z = 0; z < num; z++) {
		if (max < result[z]) { 
			max = result[z]; 
			maxNum = z;
		}
	}

	cout << BookName[maxNum];
	
	return 0;
}