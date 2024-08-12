#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int fb[100001];
    fb[0] = 0;
    fb[1] = 1;
    
    for(int i=2; i<=n; i++){
        fb[i] = fb[i-2]%1234567 + fb[i-1]%1234567;
    }
    
    return fb[n]%1234567;
}