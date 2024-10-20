#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board_origin) {
    int answer = 0;
    vector<vector<int>> board;
    board = board_origin;
    if(board_origin.size()==1) {
        if(board_origin[0][0]==0) return 1;
        else return 0;
    }
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            if(board_origin[i][j]==1){
                board[i][j]=1;
                if(j==0){
                    if(i==0){
                        board[i][j+1] = 1;
                        board[i+1][j] = 1;
                        board[i+1][j+1] = 1;
                    }else if (i==board.size()-1){
                        board[i][j+1] = 1;
                        board[i-1][j] = 1;
                        board[i-1][j+1] = 1;
                    }else{
                        board[i][j+1] = 1;
                        board[i+1][j] = 1;
                        board[i+1][j+1] = 1;
                        board[i-1][j] = 1;
                        board[i-1][j+1] = 1;
                    }
                }else if(j==board.size()-1){
                    if(i==0){
                        board[i][j-1] = 1;
                        board[i+1][j] = 1;
                        board[i+1][j-1] = 1;
                    }else if(i==board.size()-1){
                        board[i][j-1] = 1;
                        board[i-1][j] = 1;
                        board[i-1][j-1] = 1;
                    }else{
                        board[i][j-1] = 1;
                        board[i+1][j] = 1;
                        board[i+1][j-1] = 1;
                        board[i-1][j] = 1;
                        board[i-1][j-1] = 1;
                    }
                }else if(i==0){
                    board[i][j+1] = 1;
                    board[i][j-1] = 1;
                    board[i+1][j] = 1;
                    board[i+1][j-1] = 1;
                    board[i+1][j+1] = 1;
                }else if(i==board.size()-1){
                    board[i][j-1] = 1;
                    board[i][j+1] = 1;
                    board[i-1][j-1] = 1;
                    board[i-1][j] = 1;
                    board[i-1][j+1] = 1;
                }else{
                    board[i][j-1] = 1;
                    board[i][j+1] = 1;
                    board[i-1][j-1] = 1;
                    board[i-1][j] = 1;
                    board[i-1][j+1] = 1;
                    board[i+1][j-1] = 1;
                    board[i+1][j] = 1;
                    board[i+1][j+1] = 1;
                }
            }
        }
    }
    for(int i=0; i<board.size(); i++){
        answer+=count(board[i].begin(), board[i].end(), 0);
    }
    return answer;
}