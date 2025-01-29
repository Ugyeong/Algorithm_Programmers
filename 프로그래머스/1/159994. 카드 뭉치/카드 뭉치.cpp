#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    string tmp = "";
    int idx1=0, idx2=0;
    
    for(int i=0; i<goal.size(); i++){
        tmp = goal[i];
        if(idx1<=cards1.size() && tmp==cards1[idx1]){
            idx1++;
        }else if(idx2<=cards2.size() && tmp==cards2[idx2]){
            idx2++;
        }else{
            answer = "No";
            break;
        }
    }
    
    return answer;
}