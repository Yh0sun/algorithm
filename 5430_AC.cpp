#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

	int t;
	cin >> t;
	while (t--) {
		string cmd, str_arr;
		int arr_size;
		cin >> cmd >> arr_size >> str_arr;
	
		int start = 1;
		vector<int> arr;
		if (arr_size != 0) {
			for (int i = 1; i < str_arr.length(); i++) {
				if (str_arr[i] == ',' || str_arr[i] == ']') {
					arr.push_back(stoi(str_arr.substr(start, i - start)));
					start = i + 1;
				}
			}
		}
		
		int st_idx = 0, end_idx = arr_size;
		int dir = 0;  //0 -> +, 1 -> -
		for (int i = 0; i < cmd.length(); i++) {
			if (cmd[i]=='R')
				dir = (dir + 1) % 2;
			else 
				if (dir == 0) 
					st_idx++;
				else 
					end_idx--;
		}

		if (st_idx > end_idx)printf("error\n");
		else if(st_idx == end_idx)printf("[]\n");
		else {
			printf("[");
			if (dir == 0) {
				for (int i = st_idx; i < end_idx-1; i++) 
					printf("%d,", arr[i]);
				printf("%d", arr[end_idx - 1]);
			}
			else {
				for (int i = end_idx - 1; i > st_idx; i--)
					printf("%d,", arr[i]);
				printf("%d", arr[st_idx]);
			}
			printf("]\n");
		}
	}

	return 0;
}

