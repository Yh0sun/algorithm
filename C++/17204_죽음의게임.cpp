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
>>>>>>>>>>if���� �¾Ƽ� ���� ����ص� �Ʒ� for�� �� ���ư�(�� 2�����)
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
>>>>>>>>>>>>>>�ݷ�:0�� �ΰ��� �ٷ� ������ �ҷ��� ���
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