#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int answer = 0;
vector<int> visited(8,0);

void dfs(int count, int k, vector<vector<int>> dungeons){
    if(answer<count) answer = count;

    for(int i=0; i<dungeons.size(); i++){
        if(visited[i]==0 && dungeons[i][0]<=k){
            visited[i]=1;
            dfs(count+1, k-dungeons[i][1], dungeons);
            visited[i]=0;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {  
    dfs(0, k, dungeons);
    
    return answer;
}