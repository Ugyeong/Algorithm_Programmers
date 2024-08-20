#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int max = people.size()-1;
    int min = 0;
    
    while(min<max){
        if(people[min]+people[max]<=limit){
            min++;
            max--;
            answer++;
        }else{
            answer++;
            max--;
        }
    }
    
    if(min==max) answer++;
    
    return answer;
}