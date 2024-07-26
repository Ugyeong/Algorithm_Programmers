#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int count=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]==' ') {
            count=0;
            answer+=" ";
        }
        else{
            if(count%2==0){
                if(s[i]>='A' && s[i]<='Z') answer+=s[i];
                else answer+=s[i]-32;
            }else{
                if(s[i]>='a' && s[i]<='z') answer+=s[i];
                else answer+=(s[i]+32);
            }
            count++;
        }
        
    }
    return answer;
}