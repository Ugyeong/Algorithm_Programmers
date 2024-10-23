#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int idx;
    bool flag;
    
    for(int i=0; i<discount.size(); i++){
        vector<int> tmp = number;
        flag = true;
        for(int j=i; j<i+10; j++){
            if(j>=discount.size()) break;
            
            if(find(want.begin(), want.end(), discount[j])!=want.end()){
                idx = find(want.begin(), want.end(), discount[j])-want.begin();
                tmp[idx]--;
            }
        }
        for(int j=0; j<tmp.size(); j++){
            if(tmp[j]>0) flag = false;
        }
        if(flag) answer++;
    }
    return answer;
}