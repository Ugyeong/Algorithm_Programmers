#include <string>
#include <vector>

using namespace std;

int solution(int x, int y, int n) {   
    vector<int> v(1000001,1000001);
    
    v[y] = 0;
    
    for(int i=y; i>x; i--){
        if(v[i]!=1000001){
            if(i%3==0){
                v[i/3] = min(v[i/3],v[i]+1);
            }
            if(i%2==0){
                v[i/2] = min(v[i/2],v[i]+1);
            }
            if(i>n){
                v[i-n] = min(v[i-n],v[i]+1);
            }
        }
    }
    
    if(v[x]==1000001) return -1;
    else return v[x];
}