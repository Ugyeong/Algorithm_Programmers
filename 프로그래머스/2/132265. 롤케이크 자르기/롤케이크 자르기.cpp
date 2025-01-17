#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    vector<int> one(topping.size()+1, 0);
    vector<int> two(topping.size()+1, 0);
    
    int a=0;
    int b=0;
    
    for(int i=0; i<topping.size(); i++){
        if(one[topping[i]]==0) b++;
        one[topping[i]]++;
    }

    for(int i=0; i<topping.size(); i++){
        if(two[topping[i]]==0) a++;
        if(one[topping[i]]==1) b--;
    
        two[topping[i]]++;
        one[topping[i]]--;
        
        if(a==b) answer++;
    }
    return answer;
}