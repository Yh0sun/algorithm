#include<queue>
using namespace std;

int main() {
	int n;
	priority_queue<int,vector<int>,greater<int>> pq;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		if (num == 0) {
			if (!pq.empty()) {
				printf("%d\n", pq.top());
				pq.pop();
			}
			else printf("0\n");
			
		}
		else pq.push(num);
	}
	return 0;
}
