#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;

    while(1){
        if((max(a,b)-min(a,b))==1 && max(a,b)%2==0) break;
        answer++;
        if(a%2==1) a++;
        a/=2;
        if(b%2==1) b++;
        b/=2;
    }

    return answer;
}