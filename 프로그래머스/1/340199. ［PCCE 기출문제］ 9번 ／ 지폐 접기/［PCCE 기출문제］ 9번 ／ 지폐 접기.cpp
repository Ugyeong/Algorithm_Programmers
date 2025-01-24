#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    int w_min = min(wallet[0],wallet[1]);
    int w_max = max(wallet[0],wallet[1]);
    while(min(bill[0], bill[1])>w_min || max(bill[0], bill[1])>w_max){
        answer++;
        if(bill[0]>bill[1]) bill[0]/=2;
        else bill[1]/=2;
    }
    return answer;
}