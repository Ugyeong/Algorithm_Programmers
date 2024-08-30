#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int idx = 0;
    int now = 0;
    queue<int> queue;
    
    for(int i=0; i<bridge_length; i++){
        queue.push(0);
    }
    
    while(idx!=truck_weights.size()){
        answer++;
        now-=queue.front();
        queue.pop();
        if(now+truck_weights[idx]<=weight){
            queue.push(truck_weights[idx++]);
        }else{
            queue.push(0);
        }
        now+=queue.back();
    }
    
    answer+=bridge_length;
    
    return answer;
}