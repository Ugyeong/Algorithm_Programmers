#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    string tmp;
    vector<string> ans;
    
    for(int i=0; i<s.size(); i++){
        tmp = s[i];
        ans.push_back(tmp);
    }
    
    sort(ans.begin(), ans.end());
    
    for(int i=s.length()-1; i>=0; i--){
        answer += ans[i];
    }
    
    return answer;
}