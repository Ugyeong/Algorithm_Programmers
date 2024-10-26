#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    int stop = 0;
    int idx;
    int x=0, y=0;
    int a[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    vector<string> visited;
    
    for(int i=0; i<dirs.size(); i++){
        if(dirs[i]=='U') idx = 0;
        else if(dirs[i]=='D') idx = 1;
        else if(dirs[i]=='R') idx = 2;
        else if(dirs[i]=='L') idx = 3;
        
        if(x+a[idx][0]>5 || x+a[idx][0]<-5 || y+a[idx][1]>5 || y+a[idx][1]<-5) {
            continue;
        }

        if(count(visited.begin(), visited.end(),to_string(x)+to_string(x+a[idx][0])+" "+to_string(y)+to_string(y+a[idx][1]))==0 &&
           count(visited.begin(), visited.end(),to_string(x+a[idx][0])+to_string(x)+" "+to_string(y+a[idx][1])+to_string(y))==0){
            answer++;
        }
        
        visited.push_back(to_string(x)+to_string(x+a[idx][0])+" "+to_string(y)+to_string(y+a[idx][1]));
        visited.push_back(to_string(x+a[idx][0])+to_string(x)+" "+to_string(y+a[idx][1])+to_string(y));
        
        x+=a[idx][0];
        y+=a[idx][1];
    
    }
    
    return answer;
}