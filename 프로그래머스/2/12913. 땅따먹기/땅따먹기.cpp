#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    vector<int> arr = {0,0,0};
    int pre_max;
    
    for(int i=1; i<land.size(); i++){
        for(int j=0; j<4; j++){
            arr.clear();
            for(int k=0; k<4; k++){
                if(k==j) continue;
                arr.push_back(land[i-1][k]);
            }
            pre_max = *max_element(arr.begin(), arr.end());
            
            land[i][j]+=pre_max;
        }
    }
    
    answer = *max_element(land[land.size()-1].begin(), land[land.size()-1].end());
    
    return answer;
}