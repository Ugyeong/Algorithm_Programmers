#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int n = p.length();
    string tmp;
    
    for(int i=0; i<t.length()-n+1; i++){
        tmp = t.substr(i,n);
        
        // while(tmp.length()>1){
        //     if(tmp[0]!='0') break;
        //     else tmp = tmp.substr(1);
        // }
        
        if(stoll(p)>=stoll(tmp)) answer++;
    }
    
    return answer;
}