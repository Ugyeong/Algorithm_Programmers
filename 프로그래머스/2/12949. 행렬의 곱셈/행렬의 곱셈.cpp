#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    vector<int> tmp;
    int cal;
    for(int i=0; i<arr1.size(); i++){
        for(int j=0; j<arr2[0].size(); j++){
            cal = 0;
            for(int k=0; k<arr1[0].size(); k++){
                //cout<<arr1[i][k]<<"+"<<arr2[j][k]<<" ";
                cal += arr1[i][k]*arr2[k][j];
            }
            tmp.push_back(cal);
        }
        answer.push_back(tmp);
        tmp.clear();
    }
    return answer;
}