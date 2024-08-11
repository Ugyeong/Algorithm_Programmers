#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<string> chk;
    
    for(int i=0; i<s.size(); i++){
        if(s[i]=='('){
            chk.push("(");
        }else if(s[i]==')'){
            if(chk.size()==0) return false;
            chk.pop();
        }
    }
    
    if(chk.size()!=0) answer = false;
    
    return answer;
}