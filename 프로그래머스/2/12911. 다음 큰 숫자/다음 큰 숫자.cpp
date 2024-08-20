#include <string>
#include <vector>

using namespace std;

int count(int a){
    int tmp = 0;
    while(a!=0){
        if(a%2==1) tmp++;
        a/=2;
    }
    return tmp;
}

int solution(int n) {
    int answer = 0;
    int n_count = count(n);
    
    while(true){
        if(n_count == count(++n)){
            answer = n;
            break;
        }
    }
    
    return answer;
}