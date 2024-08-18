#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    string tmp = "";
    for(int i=0; i<s.size(); i++){
        if(s[i]==' '){
            if(tmp.size()>0){
                if(tmp[0]>=97) tmp[0]-=32;
                answer+=tmp;
            }
            answer += " ";
            tmp = "";
        }else{
            if(s[i]>=65 &&s[i]<=90) s[i]+=32;
            tmp+=s[i];
        }
    }
    
    if(tmp.size()>0){
        if(tmp[0]>=97) tmp[0]-=32;
        answer+=tmp;
    }
    
    return answer;
}