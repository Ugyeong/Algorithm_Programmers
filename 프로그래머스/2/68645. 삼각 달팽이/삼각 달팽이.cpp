#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> tmp;
    int max;
    int round = 0;
    int a=n-1, b=1;
    int x=0, y=1;
    
    max = (n+1)*n/2;
    
    for(int i=0; i<n; i++){
        tmp.push_back(vector<int>());
        for(int j=0; j<i+1; j++){
            tmp[i].push_back(i+1);
        }
    }
    
    for(int i=n+1; i<=max; i++){
        tmp[a][b] = i;
        
        if(x==0 && y==1){ //오른쪽으로 가던 중
            if(b+y == n || tmp[a+x][b+y]!=tmp[a+x][0]){
                x=-1;
                y=-1;
                round++;
            }
        }else if(x==-1 && y==-1){ //위로 가던 중
            if(b+y == round-1){
                x=1;
                y=0;
            }
            
        }else if(x==1 && y==0){ //아래로 가던 중
            if(tmp[a+x][b+y]!=tmp[a+x][0]){
                x=0;
                y=1;
            }
        }
        
        a+=x;
        b+=y;
        
    }
    
    for(int i=0; i<tmp.size(); i++){
        for(int j=0; j<tmp[i].size(); j++){
            answer.push_back(tmp[i][j]);
        }
    }
    
    return answer;
}