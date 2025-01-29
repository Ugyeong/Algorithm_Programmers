#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    vector<int> position(26,101);
    int sum = 0;
    
    for(int i=0; i<keymap.size(); i++){
        for(int j=0; j<keymap[i].size(); j++){
            if(position[keymap[i][j]-'A']>j) position[keymap[i][j]-'A'] = j;
        }
    }
    
    for(int i=0; i<targets.size(); i++){
        sum = 0;
        for(int j=0; j<targets[i].size(); j++){
            if(position[targets[i][j]-'A'] == 101) {
                sum = -1;
                break;
            }else sum+=position[targets[i][j]-'A']+1;
        }
        answer.push_back(sum);
    }
    
    return answer;
}