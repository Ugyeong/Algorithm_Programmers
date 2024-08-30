#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int tmp;
    int count = 0;
    
    sort(citations.begin(), citations.end());
    tmp = citations[citations.size()-1];
    
    while(true){
        count = 0;
        for(int i=0; i<citations.size(); i++){
            if(tmp<=citations[i]){
                count++;
            }
        }
        if(count>=tmp){
            return tmp;
        }
        tmp--;
    }
    
    
    return answer;
}