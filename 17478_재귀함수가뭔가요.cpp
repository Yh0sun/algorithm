#include<iostream>
using namespace std;
void recursive_func(int num,int i);

int main() {
	int num;
	int i = 0;

	cin >> num;

	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << endl;
	

	recursive_func(num, i);

	return 0;
}
void recursive_func(int n,int i) {
	for (int j = 0; j < i; j++) {
			cout << "____";
		}
	cout << "\"����Լ��� ������?\"" << endl;
	for (int j = 0; j < i; j++) {
		cout << "____";
	}
	if (i == n) {
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << endl;
		for (int j = 0; j < i; j++) {
			cout << "____";
		}
	}
	else {
		cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << endl;
		for (int j = 0; j < i; j++) {
			cout << "____";
		}
		cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << endl;
		for (int j = 0; j < i; j++) {
			cout << "____";
		}
		cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << endl;		
		recursive_func(n, ++i);
		for (int j = 0; j < i-1; ++j) {
		cout << "____";
		}
	}	
	
	cout << "��� �亯�Ͽ���." << endl;
	
	return;
}