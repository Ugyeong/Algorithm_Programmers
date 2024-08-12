#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> chk;
    int count = 0;
    int before;
    
    for(int i=0; i<progresses.size(); i++){
        if((100-progresses[i])%speeds[i]==0) chk.push_back((100-progresses[i])/speeds[i]);
        else{
            chk.push_back((100-progresses[i])/speeds[i]+1);
        }
    }
    
    before = chk[0];
    for(int i=0; i<chk.size(); i++){
        if(chk[i]<=before) count++;
        else{
            answer.push_back(count);
            count = 1;
            before = chk[i];
        }
    }
    answer.push_back(count);
    
    return answer;
}