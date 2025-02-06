#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer=0;
    long long sum1=0, sum2=0;
    int one=0, two=0;
    int size = queue1.size();
    
    for(int i=0; i<size; i++){
        sum1+=queue1[i];
        sum2+=queue2[i];
    }
    
    if(sum1==sum2) return 0;
    
    while(answer<3*size){
        if(sum1>sum2){
            sum1-=queue1[one];
            sum2+=queue1[one];
            queue2.push_back(queue1[one]);
            one++;
        }else if(sum1<sum2){
            sum1+=queue2[two];
            sum2-=queue2[two];
            queue1.push_back(queue2[two]);
            two++;
        }
        
        answer++;
        
        if(sum1==sum2) return answer;
    }
    
    return -1;
}