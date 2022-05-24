#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{

		int num;
		long long result = 0;   // ※ 1000이하의 숫자 1000000개가 있을 수 있으므로!!!!!!!!
		vector<int> v;

		cin >> num;

		for (int i = 0; i < num; ++i) {
			int tmp;
			cin >> tmp;
			v.push_back(tmp);
		}

		int max_val = *max_element(v.begin(), v.end());
		for (int i = 0; i < num; ++i) {
			if (v[i] == max_val) {
				max_val = *max_element(v.begin() + i+1, v.end());
			}
			else {
				result += (max_val - v[i]);
			}
		}

		cout << "#" << test_case << " " << result << endl;

	}
	return 0;
}
