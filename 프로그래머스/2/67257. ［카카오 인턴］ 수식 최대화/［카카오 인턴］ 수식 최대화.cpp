#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

long long cal(string a, string b, string c){
    if(b=="+") return stol(a)+stol(c);
    else if(b=="-") return stol(a)-stol(c);
    else if(b=="*") return stol(a)*stol(c);
}

long long solution(string expression) {
    long long answer = 0;
    vector<string> arr;
    vector<string> chk;
    string tmp = "";
    string p[6][3] = {{"*","+","-"}, {"*","-","+"}, 
                      {"+","*","-"},{"+","-","*"},
                      {"-","+","*"}, {"-","*","+"}};
    
    for(int i=0; i<expression.length(); i++){
        if(expression[i]=='+'||expression[i]=='-'||expression[i]=='*'){
            arr.push_back(tmp);
            tmp = expression[i];
            arr.push_back(tmp);
            tmp = "";
        }else{
            tmp+=expression[i];
        }
    }
    arr.push_back(tmp);
    
    for(int i=0; i<6; i++){
        chk = arr;
        for(int j=0; j<chk.size(); j++){
            if(chk[j]==p[i][0]){
                chk[j-1] = to_string(cal(chk[j-1], chk[j], chk[j+1]));
                chk.erase(chk.begin()+j);
                chk.erase(chk.begin()+j);
                j--;
            }
        }
        
        for(int j=0; j<chk.size(); j++){
            if(chk[j]==p[i][1]){
                chk[j-1] = to_string(cal(chk[j-1], chk[j], chk[j+1]));
                chk.erase(chk.begin()+j);
                chk.erase(chk.begin()+j);
                j--;
            }
        }
        
        for(int j=0; j<chk.size(); j++){
            if(chk[j]==p[i][2]){
                chk[j-1] = to_string(cal(chk[j-1], chk[j], chk[j+1]));
                chk.erase(chk.begin()+j);
                chk.erase(chk.begin()+j);
                j--;
            }
        }

        if(abs(stol(chk[0]))>answer) answer = abs(stol(chk[0]));
    }
    
    
    return answer;
}