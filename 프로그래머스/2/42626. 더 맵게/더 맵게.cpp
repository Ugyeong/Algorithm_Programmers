#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int tmp;
    priority_queue<int, vector<int>, greater<int>> q;
    
    for(int i=0; i<scoville.size(); i++){
        q.push(scoville[i]);
    }
    
    while(q.size()>1){
        if(q.top()>=K) return answer;
        else{
            tmp = q.top();
            q.pop();
            tmp = tmp + q.top()*2;
            q.pop();
            q.push(tmp);
            answer++;
        }
    }
    
    if(scoville.size()==1){
        if(q.top()>K) return answer;
        else return -1;
    }
}