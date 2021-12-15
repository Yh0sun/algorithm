#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int rightPosition=12,leftPosition=10;
    int rightDistance=0,leftDistance=0;
    
    for(int i=0;i<numbers.size();i++){
        if(numbers[i]==0)numbers[i]=11;
        if(numbers[i]%3==1){
            answer.push_back('L');
            leftPosition=numbers[i];
        }
        else if(numbers[i]%3==0&&numbers[i]!=0){
            answer.push_back('R');
            rightPosition=numbers[i];
        }
        else{
            leftDistance=abs(numbers[i]-leftPosition);
            leftDistance=leftDistance/3+leftDistance%3;
            rightDistance=abs(numbers[i]-rightPosition);
            rightDistance=rightDistance/3+rightDistance%3;
            if(leftDistance>rightDistance){
                answer.push_back('R');
                rightPosition=numbers[i];
            }           
            else if(leftDistance<rightDistance){
                answer.push_back('L');
                leftPosition=numbers[i];
            }
            else{
                if(hand=="right"){
                    answer.push_back('R');
                    rightPosition=numbers[i];
                }
                else {
                    answer.push_back('L');
                    leftPosition=numbers[i];
                }
            }
        }
    }
    return answer; 
}