#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<string> car;
    vector<int> time;
    int sum;
        
    for(int i=0; i<records.size(); i++){
        car.push_back(records[i].substr(6,4));
    }
    sort(car.begin(),car.end());
    car.erase(unique(car.begin(), car.end()), car.end());
    
    for(int i=0; i<car.size(); i++){
        time.clear();
        sum = 0;
        
        for(int j=0; j<records.size(); j++){
            if(car[i] == records[j].substr(6,4)){
                time.push_back(stoi(records[j].substr(0,2))*60 + 
                               stoi(records[j].substr(3,2)));
            }
        }
        
        for(int j=0; j<time.size(); j++){
            if(j%2==0) sum-=time[j];
            else sum+=time[j];
        }
        if(time.size()%2!=0) sum += 1439;
        
        //계산
        if(sum<=fees[0]) answer.push_back(fees[1]);
        else{
            if((sum-fees[0])%fees[2]==0){
                answer.push_back(fees[1] + (sum-fees[0])/fees[2]*fees[3]);
            }else{
                answer.push_back(fees[1] + ((sum-fees[0])/fees[2]+1)*fees[3]);
            }
        }
    }
    
    return answer;
}