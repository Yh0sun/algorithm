#include<iostream>
using namespace std;
class stack {
	int arr[1000] = { 0 };
	int index = -1;
public:
	void push(int a);
	void pop();
	void size();
	void empty();
	void top();
};

void stack::push(int a) {
	index++;
	arr[index] = a;
}
void stack::pop() {
	int tmp = 0;

	if (index == -1)cout << "-1" << endl;
	else if (index < -1) {
		index == -1;
		cout << "더이상pop 할수 없습니다" << endl;
	}
	else {
		tmp = arr[index];
		arr[index] = 0;
		index--;
		cout << tmp << endl;
	}
}

void stack::size() {
	cout << index + 1 << endl;
}
void stack::empty() {
	if (index == -1) cout << "1" << endl;
	else cout << "0" << endl;
}
void stack::top() {
	if (index == -1) cout << "-1" << endl;
	else cout << arr[index] << endl;
}

int main() {
	int num, order_num;
	string order;
	stack st;

	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> order;
		if (order == "push") {
			cin >> order_num;
			st.push(order_num);
		}
		if (order == "pop") st.pop();
		if (order == "size") st.size();
		if (order == "empty") st.empty();
		if (order == "top") st.top();
	}

	return 0;
}