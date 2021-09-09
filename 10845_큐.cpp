#include<iostream>
using namespace std;
class queue {
	int arr[100000] = { 0 };
	int index = -1;
	int front_ = 0;
	int back_ = -1;
public:
	void push(int a);
	void pop();
	void size();
	void empty();
	void front();
	void back();
};

void queue::push(int a) {
	index++;
	back_++;
	arr[front_ + index] = a;
}
void queue::pop() {
	int tmp = 0;

	if (index == -1)cout << "-1" << endl;
	else if (index < -1) {
		index == -1;
		cout << "더이상pop 할수 없습니다" << endl;
	}
	else {
		tmp = arr[front_];
		arr[front_] = 0;
		index--;
		front_++;
		cout << tmp << endl;
	}
}

void queue::size() {
	cout << index + 1 << endl;
}
void queue::empty() {
	if (index == -1) cout << "1" << endl;
	else cout << "0" << endl;
}
void queue::front() {
	if (index == -1) cout << "-1" << endl;
	else cout << arr[front_] << endl;
}
void queue::back() {
	if (index == -1) cout << "-1" << endl;
	else cout << arr[back_] << endl;
}

int main() {
	int num, order_num;
	string order;
	queue que;

	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> order;
		if (order == "push") {
			cin >> order_num;
			que.push(order_num);
		}
		if (order == "pop") que.pop();
		if (order == "size") que.size();
		if (order == "empty") que.empty();
		if (order == "front") que.front();
		if (order == "back") que.back();
	}

	return 0;
}