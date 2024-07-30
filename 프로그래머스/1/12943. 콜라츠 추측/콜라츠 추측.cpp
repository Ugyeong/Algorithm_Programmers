#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long tmp = num;
    while(tmp!=1){
        if(answer>=500) {
            answer = -1;
            break;
        }
        answer++;
        if(tmp%2==0) tmp = tmp/2;
        else tmp = tmp*3+1;
    }
    return answer;
}