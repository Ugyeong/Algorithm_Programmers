#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<int> v1(10,0);
    vector<int> v2(10,0);
    int count;
    
    for(int i=0; i<X.length(); i++){
        v1[X[i]-'0']+=1;
    }
    
    for(int j=0; j<Y.length(); j++){
        v2[Y[j]-'0']+=1;
    }
    
    for(int i=9; i>=0; i--){
        count = min(v1[i],v2[i]);
        for(int j=0; j<count; j++){
            answer+=to_string(i);
        }
    }
    
    if(answer.length()==0) answer = "-1";
    if(answer[0]=='0' && answer.length()>1) answer = "0";
    
    return answer;
}