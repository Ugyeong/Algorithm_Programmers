#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> one = {1,2,3,4,5};
    vector<int> two = {2,1,2,3,2,4,2,5};
    vector<int> three = {3,3,1,1,2,2,4,4,5,5};
    
    vector<int> count = {0,0,0};
    
    int one_chk = 0;
    int two_chk = 0;
    int three_chk = 0;
    
    int max = 0;
    
    for(int i=0; i<answers.size(); i++){
        if(answers[i]-one[one_chk++]==0) count[0]++;
        if(answers[i]-two[two_chk++]==0) count[1]++;
        if(answers[i]-three[three_chk++]==0) count[2]++;
        
        if(one_chk==5) one_chk-=5;
        if(two_chk==8) two_chk-=8;
        if(three_chk==10) three_chk-=10;
    }
    
    max = *max_element(count.begin(), count.end());
    for(int i=0; i<3; i++){
        if(max==count[i]) answer.push_back(i+1);
    }
    
    
    return answer;
}