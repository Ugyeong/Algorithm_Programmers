#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    answer -= lost.size();
    vector<int> chk;
    sort(lost.begin(), lost.end());
    for(int i=0; i<lost.size(); i++){
        if(count(reserve.begin(), reserve.end(), lost[i])!=0){ //lost와 reserve에 둘 다 있는 경우
            chk.push_back(lost[i]);
            lost.erase(lost.begin()+i);
            i--;
            answer++;
        }
    }
    
    for(int i=0; i<lost.size(); i++){
        if(lost[i]==1) {
            if(count(reserve.begin(), reserve.end(), lost[i]+1)!=0 &&
              count(chk.begin(), chk.end(), lost[i]+1)==0){
                chk.push_back(lost[i]+1);
                answer++;
            }
        }else if(lost[i]==n){
            if(count(reserve.begin(), reserve.end(), lost[i]-1)!=0 &&
              count(chk.begin(), chk.end(), lost[i]-1)==0){
                chk.push_back(lost[i]-1);
                answer++;
            }
        }else{
            if(count(reserve.begin(), reserve.end(), lost[i]-1)!=0 &&
              count(chk.begin(), chk.end(), lost[i]-1)==0){
                chk.push_back(lost[i]-1);
                answer++;
            }else if(count(reserve.begin(), reserve.end(), lost[i]+1)!=0 &&
              count(chk.begin(), chk.end(), lost[i]+1)==0){
                chk.push_back(lost[i]+1);
                answer++;
            }
        }
    }
    return answer;
}