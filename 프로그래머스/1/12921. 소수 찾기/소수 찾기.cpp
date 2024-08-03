#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    bool chk[1000001] = {false, };
    for(int i=2; i<=n; i++){
        if(chk[i]) continue;
        answer++;
        for(int j=i; j<=n; j+=i) chk[j]=true;
    }
    return answer;
}