#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    int num;
    
    priority_queue<int> q;
    for(int i=0; i<works.size(); i++) q.push(works[i]);
    
    while(n>0){
        if(q.top()==0) break;
        
        num = q.top();
        q.pop();
        q.push(num-1);
        
        n--;
    }
    
    
    for(int i=0; i<works.size(); i++){
        answer+=pow(q.top(),2);
        q.pop();
    }
    
    return answer;
}