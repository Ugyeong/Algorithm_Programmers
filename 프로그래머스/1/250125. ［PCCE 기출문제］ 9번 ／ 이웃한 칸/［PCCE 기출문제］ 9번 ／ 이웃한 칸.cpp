#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    string chk = board[h][w];
    vector<pair<int,int>> vv;
    
    vv.push_back(make_pair(h-1,w));
    vv.push_back(make_pair(h+1,w));
    vv.push_back(make_pair(h,w-1));
    vv.push_back(make_pair(h,w+1));
    
    for(int i=0; i<vv.size(); i++){
        if(vv[i].first<0 || vv[i].first==board.size() || 
          vv[i].second<0 || vv[i].second==board.size())
            continue;
        if(board[vv[i].first][vv[i].second]==chk) answer++;
    }


    return answer;
}