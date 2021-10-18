#include<iostream>
#include<queue>
using namespace std;

int main() {
	int qjsWo, NumOfPeople;
	queue<int> que;
	queue<int> result;

	cin >> NumOfPeople >> qjsWo;

	for (int i = 1; i <= NumOfPeople; i++) {
		que.push(i);
	}
	
	while(!que.empty()) {
		for (int j = 1; j <= qjsWo; j++) {
			if (j == qjsWo)result.push(que.front());
			else
			que.push(que.front());
		
			que.pop();	
		}
	}
	
	cout << "<";
	for (int k = 1; k <= NumOfPeople; k++) {
		cout << result.front();
		result.pop();
		if (k < NumOfPeople)cout << ", ";
	}
	cout << ">";
	return 0;
}