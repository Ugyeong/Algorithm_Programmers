#include <string>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;

int chk(string tmp){
    long long int num = 0;
    
    if(tmp!="") num = stol(tmp);
    
    if(num>1){
        for(long long int i=2; i<=sqrt(num); i++){
            if(num%i==0){
                return 0;
            }
        }
    }else return 0;

    return 1;
}

int solution(int n, int k) {
    int answer = 0;
    stack<int> s;
    string tmp = "";
    
    while(n>=k){
        s.push(n%k);
        n/=k;
    }
    s.push(n);
    
    while(!s.empty()){
        if(s.top()==0){
            answer+=chk(tmp);
            tmp = "";
        }else tmp+=to_string(s.top());
        s.pop();
    }
    answer+=chk(tmp);
    
    return answer;
}