#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	int NumOfWord, result;
	string word[50] = {};
	
	cin >> NumOfWord;

	for (int i = 0; i < NumOfWord; i++) {
		cin >> word[i];
	}

	sort(word, word + NumOfWord);
	
	result = NumOfWord;

	for (int j = 0; j < NumOfWord; j++) {
		for (int k = j + 1; k < NumOfWord; k++) {
			if (word[k].find(word[j]) == 0) {
				--result; 
				break;
			}
		}
	}

	cout << result;

	return 0;
}