#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    int tmp;
    for(int i=1; i<=number; i++){
        tmp = 0;
        for(int j=1; j<=sqrt(i); j++){
            if(i%j==0){
                if(j==sqrt(i)){
                    tmp++;
                }else{
                    tmp+=2;
                }
            }
            if(tmp>limit){
                tmp = power;
                break;
            }
        }
        answer+=tmp;
    }
    return answer;
}