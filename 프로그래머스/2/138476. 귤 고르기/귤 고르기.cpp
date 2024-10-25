#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int sum = 0;
    int max = *max_element(tangerine.begin(), tangerine.end());
    vector<int> v(max+1,0);
    
    for(int i=0; i<tangerine.size(); i++){
        v[tangerine[i]]++;
    }
    
    sort(v.begin(), v.end());
    
    for(int i=v.size()-1; i>=0; i--){
        if(sum>=k) break;
        else{
            answer++;
            sum+=v[i];
        }
    }
    
    return answer;
}