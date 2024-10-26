#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int n) {
    string answer = "";
    int tmp;
    int count[4] = {4,1,2};

    while(n!=0){
        answer = to_string(count[n%3]) + answer;
        if(n%3==0) n=n/3-1;
        else n/=3;
    }
    
    return answer;
}