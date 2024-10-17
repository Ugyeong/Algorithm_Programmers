#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int search(vector<vector<int>> v){
    vector<bool> visited(v.size()+1);
    queue<int> q;
    int count = 1;
    int tmp;
    
    q.push(1);
    visited[q.front()] = true;
    
    while(!q.empty()){
        for(int i=0; i<v[q.front()].size(); i++){
            tmp = v[q.front()][i];
            if(!visited[tmp]) {
                q.push(tmp);
                visited[tmp] = true;
                count++;
            }
        }
        q.pop();
    }
    int count2 = v.size()-count-1;
    return abs(count - count2);
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    int a,b;

    for(int i=0; i<wires.size(); i++){
        vector<vector<int>> tmp(n+1); //위치에 따라서 오류남
        for(int j=0; j<wires.size(); j++){
            if(i==j) continue;
            a = wires[j][0];
            b = wires[j][1];
            tmp[a].push_back(b);
            tmp[b].push_back(a);
        }
        answer = min(answer, search(tmp));
    }
    
    return answer;
}