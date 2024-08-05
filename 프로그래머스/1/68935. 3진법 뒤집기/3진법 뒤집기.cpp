#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    string tmp = "";
    int chk = 1;
    while(n!=0){
        tmp += to_string(n%3);
        n/=3;
    }
    
    for(int i=tmp.size()-1; i>=0; i--){
        answer += (tmp[i]-'0')*chk;
        chk*=3;
    }

    return answer;
}