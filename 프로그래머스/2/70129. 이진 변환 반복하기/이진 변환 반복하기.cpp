#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int times = 0;
    int count = 0;
    string tmp;
    int length;
    stack<int> stack;
    
    while(s!="1"){
        times++;
        tmp = "";
        for(int i=0; i<s.size(); i++){
            if(s[i]=='1') tmp+="1";
            else count++;
        }
        length = tmp.size();
        while(length!=0){
            stack.push(length%2);
            length/=2;
        }
        tmp = "";
        while(!stack.empty()){
            tmp += to_string(stack.top());
            stack.pop();
        }
        s = tmp;
    }
    
    answer.push_back(times);
    answer.push_back(count);
    
    return answer;
}