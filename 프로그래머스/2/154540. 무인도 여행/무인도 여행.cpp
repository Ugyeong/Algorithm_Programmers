#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> tmp;
vector<vector<int>> visited;

int map_count(int a, int b){
    string chg = "";
    if(a<0 || a>tmp.size()-1 || b<0 || b>tmp[0].size()-1) return 0;
    
    if(visited[a][b]==1) return 0;
    if(tmp[a][b]=='X') {
        visited[a][b]=1;
        return 0;
    }
    
    visited[a][b]=1;
    chg = tmp[a][b];
    return stoi(chg) + map_count(a-1,b) + map_count(a,b-1) + map_count(a,b+1) + map_count(a+1,b);
    
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    tmp = maps;
    int chk = 0;
    
    for(int i=0; i<maps.size(); i++){
        visited.push_back(vector<int>());
        for(int j=0; j<maps[0].size(); j++){
            visited[i].push_back(0);
        }
    }
    
    for(int i=0; i<maps.size(); i++){
        for(int j=0; j<maps[0].size(); j++){
            chk = map_count(i,j);
            if(chk!=0) answer.push_back(chk);
        }
    }
    
    sort(answer.begin(), answer.end());
    if(answer.size()==0) answer.push_back(-1);
    
    return answer;
}