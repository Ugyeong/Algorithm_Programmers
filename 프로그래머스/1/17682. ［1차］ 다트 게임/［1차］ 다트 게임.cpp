#include <string>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int ans = 0;
    vector<int> score;
    vector<string> str;
    string tmp = "";
    
    score.push_back(0);
    
    for(int i=0; i<dartResult.size(); i++){
        tmp+=dartResult[i];
        if(i<=dartResult.size()-2){
            if(!(dartResult[i]>='0' && dartResult[i]<='9') &&
               (dartResult[i+1]>='0' && dartResult[i+1]<='9')){
                str.push_back(tmp);
                tmp = "";
            }
        }
    }
    str.push_back(tmp);
    
    for(int i=1; i<4; i++){
        tmp = "";
        for(int j=0; j<str[i-1].size(); j++){
            if(str[i-1][j]=='S'){
                ans = stoi(tmp);
                tmp = "";
            }else if(str[i-1][j]=='D'){
                ans = pow(stoi(tmp),2);
                tmp = "";
            }else if(str[i-1][j]=='T'){
                ans = pow(stoi(tmp),3);
                tmp = "";
            }else if(str[i-1][j]=='*'){
                ans*=2;
                score[i-1]*=2;
            }else if(str[i-1][j]=='#'){
                ans*=-1;
            }else{
                tmp+=str[i-1][j];
            }
        }
        score.push_back(ans);
    }
    
    answer = score[1]+score[2]+score[3];
    
    return answer;
}