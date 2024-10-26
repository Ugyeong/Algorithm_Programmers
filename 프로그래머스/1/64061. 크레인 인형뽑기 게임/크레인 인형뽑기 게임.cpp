#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int tmp;
    stack<int> s;
    
    for(int i=0; i<moves.size(); i++){
        tmp = 0;
        for(int j=0; j<board.size(); j++){
            if(board[j][moves[i]-1]!=0){
                tmp = board[j][moves[i]-1];
                board[j][moves[i]-1]=0;
                break;
            }
        }
        
        if(tmp!=0){
            if(s.size()>0){
                if(tmp==s.top()){
                    s.pop();
                    answer++;
                }else{
                    s.push(tmp);
                }
            }else {
                s.push(tmp);
            }
        }
        
    }

    return answer*2;
}