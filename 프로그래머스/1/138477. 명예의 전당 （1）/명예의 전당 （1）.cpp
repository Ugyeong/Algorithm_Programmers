#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> tmp;
    
    for(int i=0; i<score.size(); i++){
        tmp.push_back(score[i]);
        sort(tmp.begin(), tmp.end());
        if(tmp.size()>k){
            tmp.erase(tmp.begin());
        }
        answer.push_back(tmp[0]);
    }
    
    return answer;
}