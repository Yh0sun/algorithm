#include<iostream>
using namespace std;

int main() {
	
	int t_case, floor, num; // 테스트 케이스 수, 층, 호
	
	cin >> t_case;
	int* result = new int [t_case];	

	for (int i = 0; i < t_case; i++) {
		cin >> floor >> num;
				
		int** arr = new int* [floor + 1];
	
		for (int i = 0; i < floor+1; ++i) {		
			arr[i] = new int[num];
			for (int j = 0; j < num; j++) {
				arr[i][j] = 0;
			}
		}

		for (int j = 0; j < num; j++) {		
			arr[0][j] = j+1;		
		}

		for (int j = 1; j <= floor; j++) {
			for (int k = 0; k < num; k++) {
				//arr[j][k] = { 0 };
				for (int as = 0; as <= k; as++) {
					arr[j][k] = arr[j][k] + arr[j - 1][as];
				}
				result[i] = arr[j][k];
			}
		}
		for (int ss = 0; ss < floor; ss++)             
			delete[] arr[ss];
		delete[] arr;	
	}
	
	for (int i = 0; i < t_case; i++)
		cout << result[i] << endl;

	return 0;
}