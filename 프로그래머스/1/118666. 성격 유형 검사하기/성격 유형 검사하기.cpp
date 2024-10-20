#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    vector<string> type = {"R","T","C","F","J","M","A","N"};
    int count[9] = {0,};
    int idx;
    string tmp = "";
    
    for(int i=0; i<survey.size(); i++){
        if(choices[i]<4){
            tmp = survey[i][0];
            idx = find(type.begin(), type.end(), tmp) - type.begin();
            count[idx]+=(4-choices[i]);
        }else if(choices[i]>4){
            tmp = survey[i][1];
            idx = find(type.begin(), type.end(), tmp) - type.begin();
            count[idx]+=(choices[i]-4);
        }
    }
    
    for(int i=0; i<type.size(); i+=2){
        if(count[i]==count[i+1]) answer+=type[i];
        else {
            if(count[i]>count[i+1]) answer+=type[i];
            else answer+=type[i+1];
        }
    }
    
    return answer;
}