#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    long long chk;
    int tmp;
    
    for(int i=0; i<numbers.size(); i++){
        if(numbers[i]%2==0){
            answer.push_back(numbers[i]+1);
            continue;
        }
        if((numbers[i]/2)%2==0){
            answer.push_back((numbers[i]/2+1)*2);
            continue;
        }
        
        tmp = 0;
        chk = numbers[i];
        
        while(true){
            if(chk%2==0){
                answer.push_back(numbers[i]+pow(2,tmp)-pow(2,tmp-1));
                break;
            }
            chk/=2;
            tmp++;
        }

    }
    
    return answer;
}