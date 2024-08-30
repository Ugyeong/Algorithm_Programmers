#include <string>
#include <vector>

using namespace std;
int solution(vector<int> priorities, int location) {
    int answer = 0;
    bool flag = true;
    bool bigtest = true;
    int idx = 0;
    
    while(flag){
        bigtest = true;
        for(int i=0; i<priorities.size(); i++){
            if(priorities[idx]<priorities[i]){
                bigtest = false;
                break;
            }
        }
        
        if(bigtest){
            answer++;
            priorities[idx] = 0;
            if(idx==location) flag = false;
        }
        
        idx++;
        if(idx==priorities.size()){
            idx = 0;
        }
    }
    
    return answer;
}