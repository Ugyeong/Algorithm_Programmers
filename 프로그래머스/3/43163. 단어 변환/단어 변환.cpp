#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
vector<string> arr;
vector<int> visited(51);
int answer = 51;

bool check(string a, string b){ //한자리만 변했는지 확인
    int count = 0;
    for(int i=0; i<a.length(); i++){
        if(a[i]!=b[i]) count++;
    }
    
    if(count == 1) return true;
    else return false;
}

void dfs(string str, int num, string target){
    string tmp="";
    
    if(num>=answer) return;
    if(target==str){
        if(answer>num) answer = num;
        return;
    }
    
    for(int i=0; i<arr.size(); i++){
        tmp = arr[i];
        if(check(str, tmp) && visited[i]==0){
            visited[i]=1;
            dfs(tmp, ++num, target);
            visited[i]=0;
        }
    }
    
    return;
}

int solution(string begin, string target, vector<string> words) {
    if(find(words.begin(), words.end(), target)==words.end()) return 0;
    
    arr = words;
    dfs(begin, 0, target);
    
    if(answer==51) return 0;
    
    return answer;
}