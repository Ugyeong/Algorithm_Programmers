#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int check = 1;
    char tmp;
    vector<int> count = {0,0};
    
    for(int i=0; i<s.length(); i++){
        if(check){
            tmp = s[i];
            count[0] = 0;
            count[1] = 0;
            answer++;
            check = 0;
        }
        
        if(tmp==s[i]) count[0]++;
        else count[1]++;
        
        if(count[0]==count[1]) check = 1;
    }
    
    return answer;
}