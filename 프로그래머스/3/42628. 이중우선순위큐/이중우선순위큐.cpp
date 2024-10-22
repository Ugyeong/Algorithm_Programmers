#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> tmp;
    string str = "";
    
    for(int i=0; i<operations.size(); i++){
        if(operations[i][0]=='I'){
            tmp.push_back(stoi(operations[i].substr(2)));
            sort(tmp.begin(), tmp.end());
        }else if(operations[i][0]=='D'){
            if(tmp.size()==0) continue;
            str = operations[i].substr(2);
            if(str=="-1") tmp.erase(tmp.begin());
            else if(str=="1") tmp.erase(tmp.begin()+tmp.size()-1);
        }
    }
    
    if(tmp.size()==0) {
        answer.push_back(0);
        answer.push_back(0);
    }else{
        answer.push_back(tmp[tmp.size()-1]);
        answer.push_back(tmp[0]);
    }
    
    
    return answer;
}