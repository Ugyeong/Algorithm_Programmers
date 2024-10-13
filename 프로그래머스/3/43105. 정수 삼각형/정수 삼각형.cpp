#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> chk;
    chk.push_back(vector<int>());
    chk[0].push_back(triangle[0][0]); //0번째 행에 추가
    
    for(int i=1; i<triangle.size(); i++){ //행마다 반복
        chk.push_back(vector<int>());
        for(int j=0; j<triangle[i].size(); j++){
            if(j==0){
                chk[i].push_back(chk[i-1][0] + triangle[i][j]);
            }else if(j==triangle[i].size()-1){
                chk[i].push_back(chk[i-1][j-1] + triangle[i][j]);
            }else{
                chk[i].push_back(max(chk[i-1][j-1],chk[i-1][j]) + triangle[i][j]);
            }
        }
    }
    
    answer = *max_element(chk[triangle.size()-1].begin(), chk[triangle.size()-1].end());
  
    return answer;
}