#include <string>
#include <vector>
#include <stack>

using namespace std;

bool check(string str){
    stack<int> s;
    
    for(int i=0; i<str.length(); i++){
        if(str[i]=='(') s.push(1);
        if(str[i]==')') {
            if(s.empty()) return false;
            else s.pop();
        }
    }
    
    if(s.empty()) return true;
    else return false;
}

string bfs(string str){
    int a=0, b=0;
    int idx = 0;
    string reverse = "";
    
    if(str.length()==0) return "";
    for(int i=0; i<str.length(); i++){
        if(str[i]=='(') a++;
        else if(str[i]==')') b++;
        
        if(a==b){ //균형잡인 문자열
            idx = i;
            break;
        }
    }
    
    if(check(str.substr(0,idx+1))){ //올바른 문자열 체크
        return str.substr(0,idx+1) + bfs(str.substr(idx+1));
    }else{
        for(int i=1; i<idx; i++){
            if(str[i]=='(') reverse+=')';
            else reverse+='(';
        }
        return '(' + bfs(str.substr(idx+1)) + ')' + reverse;
    }
    
}

string solution(string p) {
    string answer = "";
    
    answer = bfs(p);
        
    return answer;
}