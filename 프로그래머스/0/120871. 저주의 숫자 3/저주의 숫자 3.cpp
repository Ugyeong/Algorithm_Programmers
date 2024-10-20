#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> list;
    int count = 0;
    string tmp = "";
    bool flag = true;
    
    while(list.size()<=n){
        count++;
        tmp = to_string(count);
        flag = true;
        if(count%3==0) flag = false;
        for(int i=0; i<tmp.size(); i++){
            if(tmp[i]=='3') {
                flag = false;
                break;
            }
        }
        
        if(flag){
            list.push_back(count);
        }
    }
    
    return list[n-1];
}