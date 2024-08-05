#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int tmp;
    for(int i=1; i<=min(n,m); i++){
        if(n%i==0 && m%i==0) tmp = i;
    }
    answer.push_back(tmp);
    
    for(int i=max(n,m); i<=n*m; i++){
        if(i%n==0 && i%m==0) {
            tmp = i;
            break;
        }
    }
    answer.push_back(tmp);
    
    return answer;
}