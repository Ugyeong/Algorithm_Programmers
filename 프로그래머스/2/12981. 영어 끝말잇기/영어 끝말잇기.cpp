#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int count = 0; //몇번째 차례인지 카운트
    //몫+1이 몇번째인지 나머지가 누구인지
    bool flag = true;
    
    for(int i=1; i<words.size(); i++){
        if(words[i-1].substr(words[i-1].size()-1) != words[i].substr(0,1)
           || find(words.begin(), words.begin()+i-1, words[i]) != words.begin()+i-1){
            flag = false;
            if((i+1)%n==0){
                answer.push_back(n);
                answer.push_back((i+1)/n);
            }else{
                answer.push_back((i+1)%n);
                answer.push_back((i+1)/n+1);
            }
            break;
        }
    }
    
    if(flag) {
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}