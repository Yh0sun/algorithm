#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {

	int n, num;
	int mid_val;

	priority_queue<int> small_pq;
	priority_queue<int> big_pq;

	scanf("%d %d", &n, &num);
	mid_val = num;
	printf("%d ", mid_val);

	for (int i = 1; i < n; i++) {
		scanf("%d", &num);
		
		if (mid_val < num)big_pq.push(-num);
		else small_pq.push(num);
	
		if (i % 2 == 1) {
			if(small_pq.size() > big_pq.size()){
				big_pq.push(-mid_val);
				mid_val = small_pq.top();
				small_pq.pop();
			}
		}
		
		else {	
			if (small_pq.size() < big_pq.size()) {
				small_pq.push(mid_val);
				mid_val = -big_pq.top();
				big_pq.pop();
			}
		}
	
		printf("%d ", mid_val);
	}

	return 0;
}
