#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    char tmp;
    int count = 0;
    
    for(int i=0; i<s.length(); i++){
        tmp = s[i];
        count = 0;
        
        while(count<index){
            tmp++;
            if(tmp>'z') tmp-=26;
            if(skip.find(tmp)==std::string::npos){
                count++;
            }
        }
        
        answer+=tmp;
    }
    
    return answer;
}