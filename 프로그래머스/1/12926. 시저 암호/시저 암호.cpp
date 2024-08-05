#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int i=0; i<s.length(); i++){
        if(s[i]==' '){
            answer += " ";
            continue;
        }
        
        if((s[i]<='Z' && (s[i]+n)>'Z') || (s[i]>='a' && (s[i]+n)>'z')){
            answer += s[i] + n -26;
        }else{
            answer += s[i] + n;
        }
    }
    return answer;
}