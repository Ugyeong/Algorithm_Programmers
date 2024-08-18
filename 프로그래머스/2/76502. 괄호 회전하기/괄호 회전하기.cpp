#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    vector<string> left = {"(", "{", "["};
    vector<string> right = {")", "}", "]"};
    stack<string> stack;
    bool flag = true;
    string tmp = "";
    
    for(int i=0; i<s.size(); i++){
        flag = true;
        for(int j=0; j<s.size(); j++){
            tmp = s[j];
            if(find(left.begin(), left.end(), tmp) != left.end()){ //여는 괄호의 경우
                stack.push(right[find(left.begin(), left.end(), tmp)-left.begin()]);
            }else{ //닫는 괄호의 경우
                if(stack.empty()){
                    flag = false;
                    break;
                }else{
                    if(stack.top()==tmp){
                        stack.pop();
                    }else{
                        stack = {}; //스택 초기화
                        flag = false;
                        break;
                    }
                }
            }
        }
        
        if(!stack.empty()) flag = false;
        
        if(flag) answer++;
        
        s = s.substr(1) + s[0]; //회전
    }
    return answer;
}