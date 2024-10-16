#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> tmp;
    string change = "";
    
    for(int i=0; i<s.length(); i++){
        //change = s[i];
        if(tmp.size()>0 && s[i]==tmp.top()) tmp.pop();
        else tmp.push(s[i]);
    }

    if(tmp.size()==0) return 1;
    else return 0;
}