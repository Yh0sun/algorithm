#include<iostream>
using namespace std;

int main() {
	int numofpeople, bosung, next = 0;
	int point[150] = { 0 };

	cin >> numofpeople >> bosung;

	for (int i = 0; i < numofpeople; i++) {
		cin >> point[i];
	}

	for (int i = 1; i < numofpeople; i++) {
		next = point[next];
		if (next == bosung) {
			cout << i;
			break;
		}
		if (i == (numofpeople - 1)) {
			cout << "-1";
		}
	}
	
	return 0;
}
/*
int main() {
	int numofpeople, bosung, next;
	int point[150] = { 0 };

	cin >> numofpeople >> bosung;

	for (int i = 0; i < numofpeople; i++) {
		cin >> point[i];
	}

	next = point[0];         
	if (next == bosung) {    
		cout << "1";          
	}                       
>>>>>>>>>>if문이 맞아서 값을 출력해도 아래 for문 또 돌아감(값 2번출력)
	for (int i = 2; i < numofpeople; i++) {
		next = point[next];
		if (next == bosung) {
			cout << i;
			break;
		}
		if (i == numofpeople - 1) {
			cout << "-1";
		}
	}
	
	return 0;
}


int main() {
	int numofpeople, bosung, next;
	int point[150] = { 0 };

	cin >> numofpeople >> bosung;

	for (int i = 0; i < numofpeople; i++) {
		cin >> point[i];
	}

	next = point[0];	
>>>>>>>>>>>>>>반례:0번 인간이 바로 보성이 불렀을 경우
	for (int i = 1; i < numofpeople; i++) {
		next = point[next];
		if (next == bosung) {
			cout << i + 1;
			break;
		}
		if (i == numofpeople - 1) {
			cout << "-1";
		}
	}

	return 0;
}
*/