#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    string first, second, third;
    
    for(int i=0; i<record.size(); i++){
        stringstream ss(record[i]);
        ss>>first>>second>>third;
        if(first == "Enter"){
            if(m.find(second) != m.end()){
                m[second] = third;
            }else{
                m.insert({second, third});
            }
        }else if(first == "Change"){
            m[second] = third;
        }
    }
    
    for(int i=0; i<record.size(); i++){
        stringstream ss(record[i]);
        ss>>first>>second>>third;
        
        if(first == "Enter"){
            answer.push_back(m[second]+"님이 들어왔습니다.");
        }else if(first == "Leave"){
            answer.push_back(m[second]+"님이 나갔습니다.");
        }
    }
    
    return answer;
}