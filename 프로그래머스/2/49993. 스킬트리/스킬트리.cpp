#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int idx;
    bool flag;
    vector<char> str;
    
    for(int i=0; i<skill.length(); i++){
        str.push_back(skill[i]);
    }
    
    for(int i=0; i<skill_trees.size(); i++){
        vector<int> check(skill.length());
        flag = true;
        for(int j=0; j<skill_trees[i].length(); j++){
            if(find(str.begin(), str.end(), skill_trees[i][j])==str.end()){
                continue;
            }else{
                idx = find(str.begin(), str.end(), skill_trees[i][j])-str.begin();
                for(int k=0; k<idx; k++){
                    if(check[k]==0){
                        flag = false;
                        break;
                    }
                }
                if(flag) check[idx]=1;
            }
        }
        if(flag) answer++;
    }
    return answer;
}