#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {

    int answer = 0;
    vector<int> stack;

    int num;
    int j;

    for (int i = 0; i < moves.size(); i++) {

        num = moves[i] - 1;
        j = 0;

        while (true) {
            if (board[j][num] != 0)
            {
                stack.push_back(board[j][num]);
                board[j][num] = 0;
                break;
            }            
            if (j == board.size() - 1 && board[j][num] == 0) {
                break;
            }
            j++;
        }

        if (stack.size() > 1) {
            if (stack[stack.size() - 1] == stack[stack.size() - 2]) {
                stack.pop_back();
                stack.pop_back();
                answer+=2;
            }
        }

    }
    return answer;
}