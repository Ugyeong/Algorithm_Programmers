#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int a=0, b=0, k=0;
vector<vector<int>> tmp;

bool chk(vector<vector<int>> arr){
    int cmp = arr[0][0];
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[0].size(); j++){
            if(cmp!=arr[i][j]) return false;
        }
    }
    return true;
}

int p(vector<vector<int>> arr){
    if(arr.size()==1){
        if(arr[0][0]==0) a++;
        else b++;
        return 0;
    }
    
    if(chk(arr)){
        if(arr[0][0]==0) a++;
        else b++;
        return 0;
    }else{
        tmp.clear();
        for(int i=0; i<arr.size()/2; i++){
            tmp.push_back(vector<int>());
            for(int j=0; j<arr.size()/2; j++){
                tmp[i].push_back(arr[i][j]);
            }
        }
        p(tmp);
        
        tmp.clear();
        for(int i=0; i<arr.size()/2; i++){
            tmp.push_back(vector<int>());
            for(int j=arr.size()/2; j<arr.size(); j++){
                tmp[i].push_back(arr[i][j]);
            }
        }
        p(tmp);
        
        tmp.clear();
        k=0;
        for(int i=arr.size()/2; i<arr.size(); i++){
            tmp.push_back(vector<int>());
            for(int j=0; j<arr.size()/2; j++){
                tmp[k].push_back(arr[i][j]);
            }
            k++;
        }
        p(tmp);
        
        tmp.clear();
        k=0;
        for(int i=arr.size()/2; i<arr.size(); i++){
            tmp.push_back(vector<int>());
            for(int j=arr.size()/2; j<arr.size(); j++){
                tmp[k].push_back(arr[i][j]);
            }
            k++;
        }
        p(tmp);
    }
    return 0;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    
    p(arr);
    
    answer.push_back(a);
    answer.push_back(b);
    
    return answer;
}