#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    int answer = 0;
    vector<int> v = {781, 156, 31, 6, 1};
    int tmp;
    
    for(int i=0; i<word.length(); i++){
        if(word[i]=='A') tmp = 0*v[i]+1;
        else if(word[i]=='E') tmp = 1*v[i]+1;
        else if(word[i]=='I') tmp = 2*v[i]+1;
        else if(word[i]=='O') tmp = 3*v[i]+1;
        else if(word[i]=='U') tmp = 4*v[i]+1;

        answer+=tmp;
    }
    
    return answer;
}